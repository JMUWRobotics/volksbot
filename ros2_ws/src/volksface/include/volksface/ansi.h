/////////////////////////////////////////////////////////////////////////////
// @file    ansi.h
// @brief   Collection of usefull Ansi Escape Code Macros
// @author  Nico Schubert
// @date    03.10.2025
/////////////////////////////////////////////////////////////////////////////

/**
 * Ansi escape codes 
 * This header summarizes the most usefull ansi escape codes
 * Theses escape codes are generally understood by all terminals
 * and are used for multiple things including:
 *  - Formatting text (Bold, Italic, strikethrough, underlined etc.)
 *  - coloring text (foreground, background, blinking etc.)
 *  - moving the cursor or the screen
 *  - clearing the screen
 *  - and more specifics (like ringing the bell, line feeding etc.)
 */

#ifndef __ANSI_H__
#define __ANSI_H__

#define STR(s) #s
#define XSTR(s) STR(s)

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
#define SCO     CSI "s"
#define SCP     SCO
#define SCOSC   SCO

#define RCP     CSI "u"
#define SCORC   RCP

//------------------------------------------------------------------------------
// Select Graphic Rendition (SGR)
//------------------------------------------------------------------------------
// general escape sequence: CSI n m
// multiple SGRs can be combined by concatenating each sequence with a semi-colon
// => CSI n1 ; n2 ; ... ; nN m

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

#define COL(c,s) SGR(c) s SGR(0)
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


#endif