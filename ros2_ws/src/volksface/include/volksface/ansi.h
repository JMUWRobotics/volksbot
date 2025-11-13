/////////////////////////////////////////////////////////////////////////////
// @file    ansi.h
// @brief   Common ANSI escape codes for terminal text formatting and control
// @author  Nico Schubert
// @date    06.11.2025
/////////////////////////////////////////////////////////////////////////////

/**
 * Ansi escape codes 
 * 
 * This header defines a collection of ANSI escape codes that are widely
 * recognized by most terminal emulators.
 * These codes can be used to:
 *  - Format text (bold, italic, underline, strikethrough, etc.)
 *  - Apply colors (foreground, background, blinking, etc.)
 *  - Move the cursor or manipulate the screen
 *  - Clear parts of the screen or the entire display
 *  - Trigger control actions (such as ringing the bell or advancing lines)
 * 
 * To disable ANSI coloring while preserving the defined symbols,
 * define the macro `DISABLE_COLOR` as `1` before including this header:
 *
 * @code
 * #define DISABLE_COLOR 1
 * #include "ansi.h"
 * @endcode
 *
 * To disable ANSI control codes (C0, C1) while preserving the defined symbols,
 * define the macro `DISABLE_CONTROL_CODES` as `1` before including this header:
 *
 * @code
 * #define DISABLE_CONTROL_CODES 1
 * #include "ansi.h"
 * @endcode
 *
 * These macro defines are useful when switching between console output and
 * logging systems at compile time without removing ANSI-related references.
 */

#ifndef DISABLE_COLOR
#define DISABLE_COLOR 0
#endif

#ifndef DISABLE_CONTROL_CODES
#define DISABLE_CONTROL_CODES 0
#endif


//------------------------------------------------------------------------------
// Compile Time String Evaluation
//------------------------------------------------------------------------------

#define STR(s) #s
#define XSTR(s) STR(s)

#if DISABLE_CONTROL_CODES == 0
//------------------------------------------------------------------------------
// Control character set C0 (partially)
//------------------------------------------------------------------------------

#define BEL     "\x07"      // \a   // Bell
#define BS      "\x08"      // \b   // Backspace
#define HT      "\x09"      // \t   // Tab
#define LF      "\x0a"      // \n   // Line Feed
#define VT      "\x0b"      // \v   // Vertical Tab
#define FF      "\x0c"      // \f   // Form Feed
#define CR      "\x0d"      // \r   // Carriage Return
#define SUB     "\x1a"      // SUB  // substitute
#define ESC     "\x1b"      // \e   // Escape

//------------------------------------------------------------------------------
// Control character set C1 (partially)
//------------------------------------------------------------------------------

#define SP      "\x20"      // Space
#define DEL     ESC "?"     // Delete
#define DCS     ESC "P"     // Device Control String
#define CSI     ESC "["     // Control Sequence Introducer
#define ST      ESC "\\"    // String Terminator
#define SOS     ESC "X"     // Start of String

//------------------------------------------------------------------------------
// Ansi control sequences (partially)
//------------------------------------------------------------------------------

#define CUU(n)  CSI STR(n) "A"  // Cursor Up                    // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUD(n)  CSI STR(n) "B"  // Cursor Down                  // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUF(n)  CSI STR(n) "C"  // Cursor Forward               // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUB(n)  CSI STR(n) "D"  // Cursor Back                  // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CNL(n)  CSI STR(n) "E"  // Cursor Next Line             // Moves cursor to beginning of the line n (default 1) lines down. (not ANSI.SYS)
#define CPL(n)  CSI STR(n) "F"  // Cursor Previous Line         // Moves cursor to beginning of the line n (default 1) lines up. (not ANSI.SYS)
#define CHA(n)  CSI STR(n) "G"  // Cursor Horizontal Absolute   // Moves the cursor to column n (default 1). (not ANSI.SYS)
#define ED(n)   CSI STR(n) "J"  // Erase in Display             // Clears part of the screen. If n is 0 (or missing), clear from cursor to end of screen. If n is 1, clear from cursor to beginning of the screen. If n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS). If n is 3, clear entire screen and delete all lines saved in the scrollback buffer (this feature was added for xterm and is supported by other terminal applications).
#define EL(n)   CSI STR(n) "K"  // Erase in Line                // Erases part of the line. If n is 0 (or missing), clear from cursor to the end of the line. If n is 1, clear from cursor to beginning of the line. If n is 2, clear entire line. Cursor position does not change.
#define SU(n)   CSI STR(n) "S"  // Scroll Up                    // Scroll whole page up by n (default 1) lines. New lines are added at the bottom. (not ANSI.SYS)
#define SD(n)   CSI STR(n) "T"  // Scroll Down                  // Scroll whole page down by n (default 1) lines. New lines are added at the top. (not ANSI.SYS)
#define SGR(n)  CSI STR(n) "m"  // Select Graphic Rendition     // Sets colors and style of the characters following this code
#define DSR     CSI "6n"        // Device Status Report         // Reports the cursor position (CPR) by transmitting ESC[n;mR, where n is the row and m is the column.

#define CUP(n,m)  CSI STR(n) ";" STR(m) "H"     // Cursor Position                  // Moves the cursor to row n, column m. The values are 1-based, and default to 1 (top left corner) if omitted. A sequence such as CSI ;5H is a synonym for CSI 1;5H as well as CSI 17;H is the same as CSI 17H and CSI 17;1H
#define HVP(n,m)  CSI STR(n) ";" STR(m) "f"     // Horizontal Vertical Position     // Same as CUP, but counts as a format effector function (like CR or LF) rather than an editor function (like CUD or CNL). This can lead to different handling in certain terminal modes.[16]: Annex A 

// popular private sequences
#define SCO     CSI "s"         // Save the current cursor position
#define SCP     SCO             // Save the current cursor position
#define SCOSC   SCO             // Save the current cursor position

#define RCP     CSI "u"         // Restore Saved Cursor Position
#define SCORC   RCP             // Restore Saved Cursor Position

#else // DISABLE_CONTROL_CODES == 1

//------------------------------------------------------------------------------
// Control character set C0 (partially)
//------------------------------------------------------------------------------

#define BEL         // \a   // Bell
#define BS          // \b   // Backspace
#define HT          // \t   // Tab
#define LF          // \n   // Line Feed
#define VT          // \v   // Vertical Tab
#define FF          // \f   // Form Feed
#define CR          // \r   // Carriage Return
#define SUB         // SUB  // substitute
#define ESC         // \e   // Escape

//------------------------------------------------------------------------------
// Control character set C1 (partially)
//------------------------------------------------------------------------------

#define SP  "\x20"  // Space
#define DEL         // Delete
#define DCS         // Device Control String
#define CSI         // Control Sequence Introducer
#define ST          // String Terminator
#define SOS         // Start of String

//------------------------------------------------------------------------------
// Ansi control sequences (partially)
//------------------------------------------------------------------------------

#define CUU(n)      // Cursor Up                    // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUD(n)      // Cursor Down                  // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUF(n)      // Cursor Forward               // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CUB(n)      // Cursor Back                  // Moves the cursor n (default 1) cells in the given direction. If the cursor is already at the edge of the screen, this has no effect.
#define CNL(n)      // Cursor Next Line             // Moves cursor to beginning of the line n (default 1) lines down. (not ANSI.SYS)
#define CPL(n)      // Cursor Previous Line         // Moves cursor to beginning of the line n (default 1) lines up. (not ANSI.SYS)
#define CHA(n)      // Cursor Horizontal Absolute   // Moves the cursor to column n (default 1). (not ANSI.SYS)
#define ED(n)       // Erase in Display             // Clears part of the screen. If n is 0 (or missing), clear from cursor to end of screen. If n is 1, clear from cursor to beginning of the screen. If n is 2, clear entire screen (and moves cursor to upper left on DOS ANSI.SYS). If n is 3, clear entire screen and delete all lines saved in the scrollback buffer (this feature was added for xterm and is supported by other terminal applications).
#define EL(n)       // Erase in Line                // Erases part of the line. If n is 0 (or missing), clear from cursor to the end of the line. If n is 1, clear from cursor to beginning of the line. If n is 2, clear entire line. Cursor position does not change.
#define SU(n)       // Scroll Up                    // Scroll whole page up by n (default 1) lines. New lines are added at the bottom. (not ANSI.SYS)
#define SD(n)       // Scroll Down                  // Scroll whole page down by n (default 1) lines. New lines are added at the top. (not ANSI.SYS)
#define SGR(n)      // Select Graphic Rendition     // Sets colors and style of the characters following this code
#define DSR         // Device Status Report         // Reports the cursor position (CPR) by transmitting ESC[n;mR, where n is the row and m is the column.

#define CUP(n,m)    // Cursor Position                  // Moves the cursor to row n, column m. The values are 1-based, and default to 1 (top left corner) if omitted. A sequence such as CSI ;5H is a synonym for CSI 1;5H as well as CSI 17;H is the same as CSI 17H and CSI 17;1H
#define HVP(n,m)    // Horizontal Vertical Position     // Same as CUP, but counts as a format effector function (like CR or LF) rather than an editor function (like CUD or CNL). This can lead to different handling in certain terminal modes.[16]: Annex A 

// popular private sequences
#define SCO
#define SCP
#define SCOSC

#define RCP
#define SCORC

#endif


#if DISABLE_COLOR == 0
// if DISABLE_CONTROL_CODES == 1 but we still want to use colors
// we must redefine CSI and SGR
#if DISABLE_CONTROL_CODES == 1
    #define CSI "\x1b["
    #define SGR(n)  CSI STR(n) "m"  // Select Graphic Rendition     // Sets colors and style of the characters following this code
#endif

#define COL(c,s) SGR(c) s SGR(0)

#else // DISABLE_COLOR == 1

#define COL(c,s) s

#endif

//------------------------------------------------------------------------------
// Select Graphic Rendition (SGR)
//------------------------------------------------------------------------------
// general escape sequence: CSI n m
// multiple SGRs can be combined by concatenating each sequence with a semi-colon
// => CSI n1 ; n2 ; ... ; nN m

//-------------------//
//  Font Formatting  //
//-------------------//

#define RST            0
#define BOLD           1
#define FAINT          2
#define ITALIC         3
#define UNDERLINE      4
#define BLINK          5
#define BLINK_FAST     6
#define REVERSE        7
#define CONCEAL        8
#define STRIKE         9
#define DEFAULT_FONT   10
#define DUNDER         21
#define NORM_INTENSITY 22
#define NO_ITALIC      23
#define NO_UNDERLINE   24
#define NO_BLINKING    25
#define NO_REVERSE     27
#define REVEAL         28
#define NO_STRIKE      29


//----------//
//  Colors  //
//----------//

#define FG_RGB(r,g,b) 38;2;r;g;b
#define BG_RGB(r,g,b) 38;2;r;g;b

// Foreground
#define FG_BLACK   30
#define FG_RED     31
#define FG_GREEN   32
#define FG_YELLOW  33
#define FG_BLUE    34
#define FG_MAGENTA 35
#define FG_CYAN    36
#define FG_WHITE   37

// Background
#define BG_BLACK   40
#define BG_RED     41
#define BG_GREEN   42
#define BG_YELLOW  43
#define BG_BLUE    44
#define BG_MAGENTA 45
#define BG_CYAN    46
#define BG_WHITE   47

// Foreground bright
#define FG_BRIGHT_BLACK   90
#define FG_BRIGHT_RED     91
#define FG_BRIGHT_GREEN   92
#define FG_BRIGHT_YELLOW  93
#define FG_BRIGHT_BLUE    94
#define FG_BRIGHT_MAGENTA 95
#define FG_BRIGHT_CYAN    96
#define FG_BRIGHT_WHITE   97

// Background bright
#define BG_BRIGHT_BLACK   100
#define BG_BRIGHT_RED     101
#define BG_BRIGHT_GREEN   102
#define BG_BRIGHT_YELLOW  103
#define BG_BRIGHT_BLUE    104
#define BG_BRIGHT_MAGENTA 105
#define BG_BRIGHT_CYAN    106
#define BG_BRIGHT_WHITE   107

#define FG_GRAY FG_BRIGHT_BLACK
#define BG_GRAY BG_BRIGHT_BLACK



//------------------------------------------------------------------------------
// Compile Time String Manipulation
//------------------------------------------------------------------------------

#ifndef __ANSI_H__
#define __ANSI_H__

#include <cstddef>

/**
 * @brief Compile time string manipulation struct.
 *        Will transform on string literals, returning compile time strings
 */
template<std::size_t N>
struct ct_string {
    char m_string[N];

    template<std::size_t M>
    constexpr ct_string( char const(&arr)[M] ) {
        for (std::size_t i = 0; i < N && i < M; ++i)
            m_string[i] = arr[i];
    }

    // does not include trailing nil
    // so ct_string<10> has a max size of 9
    // if there is an earlier nil character, size()
    // is the length up to that nil
    constexpr std::size_t size() const {
        std::size_t r = 0;
        while(r + 1 < N && m_string[r])
            ++r;
        return r;
    }

    constexpr char& operator[](std::size_t i) { return m_string[i]; }
    constexpr char const& operator[](std::size_t i) const { return m_string[i]; }

    constexpr char const* c_str() const { return m_string; }
    constexpr operator char const*() const { return c_str(); }

    static constexpr ct_string remove_esc_ansi( ct_string<N> cts ) {
        int copy_i=0, next=0;

        for (std::size_t i = 0; i < N; ++i) {
            // if ansi remove else do not
            i += next = is_csi_sequence( cts.m_string+i );
            if( next )
                continue;

            // if C1 remove else do not
            i += next = is_C1( cts.m_string+i );
            if( next )
                continue;
            
            // if C0 remove else do not
            i += next = is_C0( cts.m_string[i] );
            if( next )
                continue;
            
            cts.m_string[copy_i++] = cts.m_string[i];
        }

        // zero pad remaining space
        for ( std::size_t i = copy_i; i < N; ++i  ) {
            cts.m_string[i] = '\x00';
        }

        return cts;
    }

    static constexpr std::size_t is_C0( const char chr ) {
        return chr == '\x07'  /* BEL */
             | chr == '\x08'  /* BS  */
             | chr == '\x09'  /* HT  */
             | chr == '\x0a'  /* LF  */
             | chr == '\x0b'  /* VT  */
             | chr == '\x0c'  /* FF  */
             | chr == '\x0d'  /* CR  */
             | chr == '\x1a'  /* SUB */
             | chr == '\x1b'; /* ESC */
    }
    static constexpr std::size_t is_C1( const char chrs[N] ) {
        #define match(x) (_is_match( chrs, x ) == sizeof(x)-1 ? sizeof(x)-1 : 0)
        return match( "\x1b?"  /* DEL */ )
             | match( "\x1bP"  /* DCS */ )
             | match( "\x1b["  /* CSI */ )
             | match( "\x1b\\" /* ST  */ )
             | match( "\x1bX"  /* SOS */ );
        
        #undef match(x)
    }
    static constexpr std::size_t is_csi_sequence( const char chrs[N] ) {
        /// searches for a csi sequence and returns its length starting at the index 0 else returns 0 if none found
        
        if ( _is_match( chrs, "\x1b[" /* CSI */ ) != sizeof("\x1b[")-1 ) {
            // is not csi
            return 0;
        }
        
        // find unique csi identifier
        return _find_min_csi<
            'A', /* CUU */
            'B', /* CUD */
            'C', /* CUF */
            'D', /* CUB */
            'E', /* CNL */
            'F', /* CPL */
            'G', /* CHA */
            'J', /* ED  */
            'K', /* EL  */
            'S', /* SU  */
            'T', /* SD  */
            'm', /* SGR */
            'n', /* DSR */
            'H', /* CUP */
            'f', /* HVP */
            's', /* SCO */
            'u'  /* RCP */>(chrs);
    }
    
    static constexpr std::size_t _is_match( const char input[N], const char reference[N], const std::size_t i=0 ) {
        /// returns the length of the longest matching sequence starting at index 0 if none returns 0
        
        for (std::size_t i = 0; i < N; ++i) {
            if ( reference[i] != input[i] ) {
                return i;
            }

            if ( reference[i] == '\x00' ) {
                break;
            }

            if ( input[i] == '\x00' ) {
                break;
            }
        }

        return 0;
    }
    static constexpr std::size_t _find( const char chr, const char str[N], const std::size_t i=0 ) {
        /// search for the first occurrence of a character in a string and return its index if found else N

        for (std::size_t i = 0; i < N; ++i) {
            if ( str[i] == '\x00' ) {
                break;
            }

            if ( str[i] == chr ) {
                return i; // found it
            }
        }

        return N;
    }

    template <typename T>
    static constexpr T min( T a0 ) {
        return a0;
    }
    template <typename T>
    static constexpr T min( T a0, T a1 ) {
        return a0 < a1 ? a0 : a1;
    }
    template <typename T, typename... Tp>
    static constexpr T min( T a0, T a1, Tp... args ) {
        return min( a0, min<T>(a1, args...) );
    }

    template <char... csi_ids>
    static constexpr auto _find_min_csi( const char str[N] ) {
        return min<std::size_t>( _find( csi_ids, str )... );
    }

};

/**
 * @brief remove ansi escape codes from string literal at compile time
 * @note prefer using '#define DISABLE_ANSI 1' before including this file
 */
template<std::size_t N>
constexpr auto remove_esc_ansi(const char (&s)[N]) {
    ct_string<N> cts{ s };
    return ct_string<N>::remove_esc_ansi(cts);
}


#endif