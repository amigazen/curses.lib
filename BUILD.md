# Build Instructions

## Build with SAS/C

The current 2.10 release of curses.lib requires SAS/C 6.58 and GNU Make to build.

src/makefile is a GNU make makefile but one that will drive SAS/C's sc compiler not GCC

### Requirements

- An Amiga
- SAS/C 6.58
- NDK3.2

### Build curses.lib with SAS/C

```
cd src
make
```

Adapting the makefile to work with smake directly is a ToDo item.

## Build with GCC

The original makefile.gcc makefile is design to drive gcc to build libcurses.a but has not been tested