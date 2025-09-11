# Changelog

All notable changes to Curses.lib for Amiga will be documented in this file.

**Author:** Simon J Raybould

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.10] - 1993-05-17

### Fixed
- Fixed bug that causes attributes to be trashed when scroll was called
- Environment variables LINES and COLS were not working properly
- Fixed bug in refresh which caused background windows to have lines erased by smaller windows over the top of them
- Fixed bug that caused WB2 fonts to not work correctly

### Added
- Added dummy function for gettmode()
- Added longname()
- Added unctrl()
- Added overlay() & overwrite()
- Added setterm()
- Added termcap/terminfo low level routines

## [2.00] - 1992-06-30

### Fixed
- Sometimes crashed in BreakHandler when interrupted by a ^C
- Now works with any font to support KS/WB 2.04
- Fixed scroll()

### Changed
- Split source into separate modules to make resultant binaries smaller when linked with the library
- Only eight colours are available in UNIX curses, so reduced the number in Amiga curses to eight as well. So colour applications should work correctly on Amigas and UNIX without alteration
- Now defaults to 1 bit plane until start_color() is called, when DEPTH is set to 3 to give 8 colours. This should make mono applications go faster than with previous versions of curses
- Added ANSI support so that curses may be run over the serial line or over a modem

## [1.23] - 1992

### Fixed
- init_color() was not working due to an overflow
- KEY_DC and KEY_BACKSPACE had the wrong defines in "curses.h"
- nonl() was not turning off carriage return to linefeed mapping
- Calls to nonl(), nl(), cbreak(), etc. had to appear after the call to initscr(). This is not the case with UNIX curses, so this is no longer necessary with Amiga curses. It is common for these initialisations to appear at the top of the code, before the call to initscr()

### Added
- Made it possible to interrupt a curses application by hitting ^C in the window it was invoked from. It will call endwin() to tidy up before exiting

## [1.22] - 1992

### Fixed
- If active screen is interlaced then the curses screen is also interlaced to allow 64 lines on a PAL system
- When there was a '\n' in a print that had inverse video set, a line of inverse spaces was added up to the end of line. This was incompatible with UNIX curses and has now been fixed

## [1.21] - 1992

### Fixed
- Fixed the range on box() to allow SPACE as a character. This allows you to draw a box of inverse spaces

### Added
- Added mvcur() to allow the cursor to be moved straight away without calling refresh()

## [1.20] - 1991-08-23

### Fixed
- Reference from address 0 in endwin() removed
- Fixed curscr to make it a copy of the physical screen. So wrefresh(curscr) will tidy up the screen to what it was last time a refresh was done

### Added
- Changed data structure for line storage to reduce the overhead in finding a particular line
- Many speed improvements
- Added doupdate() & wnoutrefresh()
- Made LINES & COLS extern ints and made them initialise to the size of the active screen when curses is invoked. This is unless the environment variables LINES and COLS exist, in which case, they will be used
- Changed the format of the libraries in an attempt to make them compatible with more linkers by making them standard amiga format
- Added many more functions, including flushinp(), resetterm() etc.

## [1.10] - 1990

### Fixed
- calling wrefresh() and other such functions with an uninitialised pointer caused the machine to hang up
- Fixed bugs in box() routine, including cursor position after drawing a box
- Fixed all of the mvwxxxx() routines such as mvwaddch(), mvwaddstr, etc. These were previously doing the move part of the instruction in stdscr instead of the specified window

### Added
- Now distributed with two libraries, one with full 32 bit addressing for large programs, and one without for smaller code
- Changed the advised line to blink in the examples. Now includes curses.lib before the other libraries
- Added more examples
- Corrected newwin/subwin control/refreshing to be more like UNIX
- Added nocrmode()
- Altered the header file to fix the mvwxxxx() bugs mentioned above
- Added mvwin()
- Added full keyboard support including Function keys and Cursor keys
- Made keypad() switch the ANSI mapping off when set to TRUE

## [1.00] - 1990-02-16

### Added
- Initial release of Curses.lib for Amiga
