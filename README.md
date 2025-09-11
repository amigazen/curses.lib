# curses.lib for Amiga

This is _curses.lib_ for Amiga, a BSD-licensed implementation of the curses screen manipulation library for Amiga computers.

## [amigazen project](http://www.amigazen.com)

*A web, suddenly*

*Forty years meditation*

*Minds awaken, free*

**amigazen project** uses modern software development tools and methods to update and rerelease classic Amiga open source software. Releases include a new AWeb, Amiga Python 2, and the ToolKit project - a universal SDK for Amiga.

Key to the amigazen project approach is ensuring every project can be built with the same common set of development tools and configurations, so the ToolKit project was created to provide a standard configuration for Amiga development. All *amigazen project* releases will be guaranteed to build against the ToolKit standard so that anyone can download and begin contributing straightaway without having to tailor the toolchain for their own setup.

The amigazen project philosophy is based on openness:

*Open* to anyone and everyone	- *Open* source and free for all	- *Open* your mind and create!

PRs for all of amigazen projects are gratefully received at [GitHub](https://github.com/amigazen/). While the focus now is on classic 68k software, it is intended that all amigazen project releases can be ported to other Amiga-like systems including AROS and MorphOS where feasible.

The original author of the *curses* software is not affiliated with the amigazen project. This software is redistributed on terms described in the documentation, particularly the file LICENSE.md

## About curses.lib for Amiga

Curses is a screen manipulation package that is used quite extensively in the UNIX environment, and a part of the POSIX specification - a POSIX platform needs a curses or ncurses implementation to be compliant. This Amiga implementation was originally created by Simon John Raybould to enable porting of UNIX programs that used curses to the Amiga platform.

### History

**Original Version (1990-1993)**: Simon John Raybould created the Amiga Curses Package to support porting UNIX applications to Amiga. The library evolved through multiple versions from 1.00 to 2.10, adding features like ANSI support, color support, and improved compatibility with UNIX curses implementations.

**amigazen project (2025)**: This version has been relicensed under BSD-2-Clause license and integrated into the amigazen project's ToolKit standard, making it available for modern Amiga development while maintaining full compatibility with the original implementation.

### Key Features

- **UNIX Compatibility**: Full curses API implementation compatible with UNIX curses programs
- **Dual Mode Support**: 
  - Custom screen mode (default) - opens a custom Amiga screen for curses applications
  - ANSI mode - works over serial connections and terminals via ANSI escape sequences
- **Color Support**: 8-color support with customizable color palettes
- **Amiga Integration**: Uses native Amiga libraries and functions for optimal performance
- **Memory Efficient**: Optimized for Amiga hardware constraints
- **BSD Licensed**: Now available under permissive BSD-2-Clause license

## About ToolKit

**ToolKit** exists to solve the problem that most Amiga software was written in the 1980s and 90s, by individuals working alone, each with their own preferred setup for where their dev tools are run from, where their include files, static libs and other toolchain artifacts could be found, which versions they used and which custom modifications they made. Open source collaboration did not exist as we know it in 2025. 

**ToolKit** from amigazen project is a work in progress to make a standardised installation of not just the Native Developer Kit, but the compilers, build tools and third party components needed to be able to consistently build projects in collaboration with others, without each contributor having to change build files to work with their particular toolchain configuration. 

All *amigazen project* releases will release in a ready to build configuration according to the ToolKit standard.

Each component of **ToolKit** is open source and will have it's own github repo, while ToolKit itself will eventually be released as an easy to install package containing the redistributable components, as well as scripts to easily install the parts that are not freely redistributable from archive.

## Building Curses.lib

Curses.lib is designed to build against the ToolKit standard, and can be built with SAS/C or GCC.

Detailed build instructions are available in the [BUILD.md](BUILD.md) file.

### Prerequisites

- SAS/C compiler (primary target)
- GCC compiler (supported)
- ToolKit development environment
- Amiga operating system 3.1 or higher

## Usage

### Basic Usage

To use curses in your Amiga programs:

1. Include `curses.h` at the top of your code instead of `stdio.h` (curses.h will include stdio.h for you)
2. Compile as normal
3. When linking, link in the library `curses.lib` before other libraries

Example link command:
```
slink sc:lib/c.o foo.o TO foo LIB lib:curses.lib lib:sc.lib lib:small.lib
```

### Mode Selection

**Custom Screen Mode (Default)**:
- Opens a custom Amiga screen for curses applications
- Provides full graphics capabilities
- Default to 2 colors (black and white)
- Call `start_color()` before `initscr()` to enable 8-color mode

**ANSI Mode**:
- Set environment variable `CURSESTYPE=ansi` before running your program
- Works over serial connections and terminals
- Compatible with terminal packages like "Term20" or "jrcomm"
- Uses ANSI escape sequences for screen control

### Example Program

```c
#include <curses.h>

int main(void)
{
    initscr();          /* Initialize curses */
    cbreak();           /* Enable cbreak mode */
    noecho();           /* Disable echo */
    
    addstr("Hello, Amiga Curses!\n");
    refresh();          /* Update screen */
    getch();            /* Wait for keypress */
    
    endwin();           /* Clean up */
    return 0;
}
```

## Frequently Asked Questions

### What is curses used for?

Curses is a screen manipulation library that provides a high-level interface for creating text-based user interfaces. It's commonly used for:
- Terminal-based applications
- Text editors
- Games
- System administration tools
- Any program that needs to control cursor position and screen display

### Why use curses instead of direct Amiga graphics?

Curses provides:
- **Portability**: Code written with curses can be easily ported between different systems
- **Simplicity**: High-level functions for common screen operations
- **Compatibility**: Works with existing UNIX software
- **Efficiency**: Optimized for text-based interfaces

### How does ANSI mode work?

When `CURSESTYPE=ansi` is set, curses uses ANSI escape sequences instead of direct graphics calls. This allows curses applications to work over serial connections, through terminal emulators, or over modems to remote terminals.

### Can I use colors?

Yes! Call `start_color()` before `initscr()` to enable 8-color mode. You can then use `init_color()` to customize the color palette and various attribute functions to set text colors.

## Contact 

- At GitHub https://github.com/amigazen/curses/ 
- on the web at http://www.amigazen.com/ (Amiga browser compatible)
- or email unsui@amigazen.com

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**. 