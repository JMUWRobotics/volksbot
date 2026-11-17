/////////////////////////////////////////////////////////////////////////////
// @file    visualizer.h
// @brief   displaying gamepad inputs depending on the drive mode in the console
// @author  Nico Schubert
// @date    12.06.2026
/////////////////////////////////////////////////////////////////////////////

#ifndef __VISUALIZER_H__
#define __VISUALIZER_H__

#include <functional>

#include "gamepad.h"
#include "drivemode.h"
#include "ros2_logger.h"

#define PRINT( ... ) LOG_ANSI( __VA_ARGS__ )

namespace animation {
namespace utils {
struct Cursor_t { 
    int line, column;

    inline Cursor_t inverse() const {
        return { -line, -column };
    }
    Cursor_t operator+( const Cursor_t& other ) const {
        return { line + other.line, column + other.column };
    }
};

static void move_cursor_relative( const Cursor_t& cursor ) {
    if (cursor.line > 0) {
        PRINT( CUD(%d), cursor.line );
    } else if (cursor.line < 0) {
        PRINT( CUU(%d), -cursor.line );
    }
    
    if (cursor.column > 0) {
        PRINT( CUF(%d), cursor.column );
    } else if (cursor.column < 0) {
        PRINT( CUB(%d), -cursor.column );
    }
}

// struct TranslationContext {
//     bool first = true;
//     Cursor_t cursor;
//     TranslationContext( const Cursor_t& cursor ) {
//         this->cursor = cursor;
//         move_cursor_relative( cursor );
//     }
//     ~TranslationContext() {
//         move_cursor_relative( cursor.inverse() );
//     }
//     bool test() {
//         first = false;
//         return first;
//     }
// };
// #define RELATIVE_CURSOR_CONTEXT(cursor) for( animation::utils::TranslationContext _ctx{cursor}; _ctx.test(); )
#define RELATIVE_CURSOR_CONTEXT(cursor) \
    move_cursor_relative( cursor ); \
    for( bool b##__LINE__{true}; b##__LINE__; b##__LINE__=false, move_cursor_relative( cursor.inverse() ) )

template< size_t N >
static constexpr size_t cstr_length( char const (&)[N] ) {
	return N-1;
}

} // namespace utils


struct AnimationElement {
    utils::Cursor_t cursor_offset; /* relative cursor offset from a common origin */
};
struct ButtonAnimationElement : public AnimationElement {
    std::function<utils::Cursor_t(button_t)> animation; /* animation function, returns the end cursor position relative to the animation origin */
    void apply(button_t state) const {
        utils::move_cursor_relative(cursor_offset);
        utils::move_cursor_relative((cursor_offset+animation(state)).inverse());
    }
};
struct AxisAnimationElement : public AnimationElement {
    std::function<utils::Cursor_t(axis_t)> animation;
    void apply(axis_t state) const {
        utils::move_cursor_relative(cursor_offset);
        utils::move_cursor_relative((cursor_offset+animation(state)).inverse());
    }
};
struct ThumbStickAnimationElement : public AnimationElement {
    /// cursor offset for the center position of the thumb stick
    /// the other offsets are relative to this center position

    AxisAnimationElement left, right, up, down;
};

struct GamepadAnimations {
    ButtonAnimationElement start;
    ButtonAnimationElement lb, rb;

    AxisAnimationElement lt, rt;
    ThumbStickAnimationElement thumb_left, thumb_right;
};

class Visualizer {
private:
    bool reprint_base_after_connected = false;
protected:
    drive_mode_t current_drive_mode;
    GamepadAnimations animations; // must be set by the inherited classes

public:
    virtual ~Visualizer() = default;

    void set_drive_mode(drive_mode_t mode) {
        current_drive_mode = mode;
        print_base();
    }

    /// @brief prints the base frame + drive mode specific information
    virtual void print_base() = 0;

    /// @brief prints the base frame for the disconnected state
    virtual void print_disconnected() = 0;

    /// @brief prints the base frame for the (re-)connected state
    virtual void print_connected() {
        reprint_base_after_connected = true;
    }

    /// @brief applies and prints the given gamepad state with the given animation elements
    void print_state(const gp_state& state) {
        if (reprint_base_after_connected) {
            reprint_base_after_connected = false;
            this->print_base();
        }

        // common animations
        animations.start.apply(state.buttons.start);
        animations.lb.apply(state.shoulder.left);
        animations.rb.apply(state.shoulder.right);

        switch(current_drive_mode) {
            case STICK_DRIVE: {
                RELATIVE_CURSOR_CONTEXT( animations.thumb_left.cursor_offset ) {
                    anim_thumb_stick_left_right( state.thumb_stick_left.left_right, animations.thumb_left );
                    anim_thumb_stick_up_down( state.thumb_stick_left.up_down, animations.thumb_left );
                }

                animate_rotation( state.thumb_stick_right.left_right );
                
                break;
            }
            case PADDLE_DRIVE: {
                animations.lt.apply(state.throttle.left);
                animations.rt.apply(state.throttle.right);
                
                RELATIVE_CURSOR_CONTEXT( animations.thumb_left.cursor_offset ) {
                    anim_thumb_stick_left_right( state.thumb_stick_left.left_right, animations.thumb_left );
                }
                
                animate_rotation( state.thumb_stick_right.left_right );
                
                break;
            }
            case TANK_DRIVE: {
                RELATIVE_CURSOR_CONTEXT( animations.thumb_left.cursor_offset ) {
                    anim_thumb_stick_up_down( state.thumb_stick_left.up_down, animations.thumb_left );
                }
                RELATIVE_CURSOR_CONTEXT( animations.thumb_right.cursor_offset ) {
                    anim_thumb_stick_up_down( state.thumb_stick_right.up_down, animations.thumb_right );
                }

                break;
            }
            default: {
                LOG_LN_ERROR( COL(FG_BRIGHT_RED, "Invalid drive mode for visualizer") );
                break;
            }
        }

        fflush(stdout);
    }

protected:
    static void anim_axis( axis_t axis, const AxisAnimationElement& anim_pos, const AxisAnimationElement& anim_neg ) {
        if( axis >= 0 ) {
            anim_pos.apply(axis);
            anim_neg.apply(0); // reset negative animation to avoid artifacts when switching from positive to negative rotation
        } else {
            anim_pos.apply(0); // reset positive animation to avoid artifacts when switching from positive to negative rotation
            anim_neg.apply(-axis);
        }
    }
    static void anim_thumb_stick_left_right( axis_t left_right, const ThumbStickAnimationElement& anim ) {
        anim_axis( left_right, anim.left, anim.right );
    }
    static void anim_thumb_stick_up_down( axis_t up_down, const ThumbStickAnimationElement& anim ) {
        anim_axis( up_down, anim.up, anim.down );
    }

    void animate_rotation( axis_t left_right ) const {
        RELATIVE_CURSOR_CONTEXT( animations.thumb_right.cursor_offset ) {
            anim_thumb_stick_left_right( left_right, animations.thumb_right );
        }
    }
};

class LogitechVisualizer : public Visualizer {
    static constexpr const char* drive_mode_frames[drive_mode_t::COUNT] = {
        // origin in left-top corner of base frame including drive mode specific information line
        // STICK_DRIVE
        "             / LT \\     Switch Mode   / RT \\                   \n"
        "  Slower--> |  LB  |              |  |  RB  | <--Faster          \n"
        "            |------+--------------V--+------|                    \n"
        "            )  ^    Back        Start    Y  (                    \n"
        "           / < + >       Logitech      X   A \\                  \n"
        "          (    v    Mode      Vibrate    B    )                  \n"
        " Accelerate ------> ^               ^         |                  \n"
        "   Steering ----> < O >           < O > <---- Rotate <-CCW / CW->\n"
        " Decelerate ------> v               v         )                  \n"
        "           \\      /^^^^^^^^^^^^^^^^^^^\\      /                 \n"
        "            \\-__-/                     \\-__-/                  \n",
        
        // PADDLE_DRIVE
        "Decelerate-> / LT \\                   / RT \\ <--Accelerate     \n"
        "  Slower--> |  LB  | Switch Mode--+  |  RB  | <--Faster          \n"
        "            |------+--------------V--+------|                    \n"
        "            )  ^    Back        Start    Y  (                    \n"
        "           / < + >       Logitech      X   A \\                  \n"
        "          (    v    Mode      Vibrate    B    )                  \n"
        "          |         ^               ^         |                  \n"
        "   Steering ----> < O >           < O > <---- Rotate <-CCW / CW->\n"
        "          (         v               v         )                  \n"
        "           \\      /^^^^^^^^^^^^^^^^^^^\\      /                 \n"
        "            \\-__-/                     \\-__-/                  \n",

        // TANK_DRIVE
        "             / LT \\     Switch Mode   / RT \\                   \n"
        "  Slower--> |  LB  |              |  |  RB  | <--Faster          \n"
        "            |------+--------------V--+------|                    \n"
        "            )  ^    Back        Start    Y  (                    \n"
        "           / < + >       Logitech      X   A \\                  \n"
        "          (    v    Mode      Vibrate    B    )                  \n"
        "    forward ------> ^               ^ <------ forward            \n"
        "          |  Left < O >           < O > Right |                  \n"
        "   backward ------> v               v <------ backward           \n"
        "           \\      /^^^^^^^^^^^^^^^^^^^\\      /                 \n"
        "            \\-__-/                     \\-__-/                  \n"
    };
    static constexpr int base_frame_line_count = 12;
    static constexpr int drive_mode_center_column = 37 / 2 + 10;

    #define ANIMATION_FUNCTION_BUTTON(str)                          \
        [](button_t state [[maybe_unused]] /*surpress warnings*/ ) {\
            PRINT( "%s", state ? COL(BOLD;BG_GREEN, str) : str );        \
            return utils::Cursor_t{ 0, utils::cstr_length(str) };   \
        }
    #define ANSI_AXIS_COLOR BOLD;FG_BRIGHT_GREEN
public:
    LogitechVisualizer(drive_mode_t initial_drive_mode = STICK_DRIVE) {
        current_drive_mode = initial_drive_mode;
        animations = {
            // start button
            { { 4, 31 }, ANIMATION_FUNCTION_BUTTON(" Start ") },

            // shoulder buttons
            { { 2, 14 }, ANIMATION_FUNCTION_BUTTON(" LB ") },
            { { 2, 39 }, ANIMATION_FUNCTION_BUTTON(" RB ") },

            // throttle axes
            { { 1, 13 }, [](axis_t value) { // "/ LT \ XXX%"
                int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                if ( percent == 0 ) {
                    PRINT( "/ LT \\     " );
                } else {
                    PRINT( COL(ANSI_AXIS_COLOR, "/ LT \\ %3d%%"), percent );
                }
                return utils::Cursor_t{ 0, utils::cstr_length("/ LT \\     ") };
            } },
            { { 1, 33 }, [](axis_t value) { // "XXX% / RT \"
                int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                if ( percent == 0 ) {
                    PRINT( "     / RT \\" );
                } else {
                    PRINT( COL(ANSI_AXIS_COLOR, "%3d%% / RT \\"), percent );
                }
                return utils::Cursor_t{ 0, utils::cstr_length("     / RT \\") };
            } },

            // left thumb stick
            { { 8, 20 }, 
                // left
                { { 0, -7 }, [](axis_t value) { // "XXX% <"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "     <");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "%3d%% <"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("     <") };
                } },
                
                // right
                { { 0, 2 }, [](axis_t value) { // "> XXX%"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( ">     ");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "> %3d%%"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length(">     ") };
                } },
                
                // up
                { { -1, 0 }, [](axis_t value) { // "^ XXX%"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "^     ");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "^ %3d%%"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("^     ") };
                } },
                
                // down
                { { 1, 0 }, [](axis_t value) { // "v XXX%"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "v     ");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "v %3d%%"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("v     ") };
                } },
            },

            // right thumb stick
            { { 8, 36 }, 
                // left
                { { 0, -7 }, [](axis_t value) { // "XXX% <"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "     <");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "%3d%% <"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("     <") };
                } },
                
                // right
                { { 0, 2 }, [](axis_t value) { // "> XXX%"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( ">     ");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "> %3d%%"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length(">     ") };
                } },
                
                // up
                { { -1, -5 }, [](axis_t value) { // "XXX% ^"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "     ^");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "%3d%% ^"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("     ^") };
                } },
                
                // down
                { { 1, -5 }, [](axis_t value) { // "v XXX%"
                    int percent = (int)( 100.0 * value / (float)AXIS_VALUE_MAX );
                    if ( percent == 0 ) {
                        PRINT( "     v");
                    } else {
                        PRINT( COL(ANSI_AXIS_COLOR, "%3d%% v"), percent );
                    }
                    return utils::Cursor_t{ 0, utils::cstr_length("     v") };
                } },
            }
        };
    }

    void print_base() override {
        PRINT("         Drive Mode: " COL(FG_BRIGHT_GREEN, "%-15s") "\n", drive_mode_str[current_drive_mode] );
        PRINT(COL(FG_GRAY, "%s"), drive_mode_frames[current_drive_mode] );
        utils::move_cursor_relative( { -base_frame_line_count, 0 } );
    }
    void print_disconnected() override {
        PRINT(COL(FG_BRIGHT_RED, "         Drive Mode: ") COL(BLINK;BG_BRIGHT_RED;FG_BLACK, "DISCONNECTED") "\n" );
        PRINT(COL(FG_BRIGHT_RED, "%s"), drive_mode_frames[current_drive_mode] );
        utils::move_cursor_relative( { -base_frame_line_count, 0 } );
    }
    void print_connected() override {
        PRINT(COL(FG_BRIGHT_GREEN, "         Drive Mode: %-15s") "\n", drive_mode_str[current_drive_mode] );
        PRINT(COL(FG_BRIGHT_GREEN, "%s"), drive_mode_frames[current_drive_mode] );
        utils::move_cursor_relative( { -base_frame_line_count, 0 } );
        Visualizer::print_connected();
    }
};

// class XBoxOneVisualizer : public Visualizer {

// };

} // namespace animation


#endif