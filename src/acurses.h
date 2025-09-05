/*
 *
 * Module      : acurses.h
 *
 * Description : Header file for AMIGA CURSES package.
 *
 * Author      : Simon Raybould  (sie@fulcrum.bt.co.uk)
 *
 * Date        : 16th February 1990
 *
 *
 *
 * THIS CODE IS COPYRIGHT S.J.R 1991, ALL RIGHTS ARE RESERVED.
 *
 * THIS SOURCE IS NOT PUBLIC DOMAIN, BUT IS FREELY DISTRIBUTABLE AS
 *                LONG AS IT REMAINS UNALTERED.
 *
 * NO IMPLICATION IS MADE AS TO IT BEING FIT FOR ANY PURPOSE AT ALL
 * I SHALL NOT BE HELD RESPONSIBLE FOR ANY LOSS OF PROPERTY OR DAMAGE
 * THAT MAY RESULT FROM ITS USE.
 *
 *
 * $Log:	acurses.h,v $
 * Revision 1.8  92/06/10  23:43:32  sie
 * Added serial support.
 * 
 * Revision 1.7  92/01/25  23:51:51  sie
 * Define for TABSIZE.
 * 
 * Revision 1.6  91/12/28  22:43:00  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.5  91/12/28  14:02:45  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.4  91/12/26  14:52:31  sie
 * Removed Next & Prev from WinStat as a list is no longer required.
 * 
 * Revision 1.3  91/09/07  11:54:19  sie
 * V2.00 curses.
 * 
 * Revision 1.2  91/08/23  21:38:47  sie
 * Port to GNU C.
 * 
 * Revision 1.1  91/02/05  21:19:43  sie
 * Initial revision
 * 
 *
 */

#include <intuition/intuition.h>
#include <intuition/screens.h>
#include <sys/types.h>
#include <exec/types.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <devices/audio.h>

#include <proto/exec.h>
#include <proto/intuition.h>
#include <proto/graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <proto/console.h>
#include <proto/dos.h>
#include <string.h>
#include "curses.h"

/* min() and max() are not part of c.lib */
#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

  
#define MAXTEXTLEN     80	/* Max text to an output call */
#define SOUNDLENGTH     2	/* Number of bytes in the sound wave */
#define CAPSMASK     0x07	/* leftshift | rightshift | capslock */
#define SHIFTMASK    0x03	/* leftshift | rightshift */
#define MAXLINES       64	/* Maximum number of lines (PAL LACE) */
#define MAXCOLS        80	/* No overscan yet */
#define TABSIZE         8	/* distance between tab stops */
#define ANSIBUFSIZ     32	/* buffers for building ANSI sequences */
/*
 * Type of curses
 */

#define CUST_CURSES    0	/* Use custom screen (default) */
#define ANSI_CURSES    1	/* Use ANSI codes to work on serial lines */

/*
 *    characters
 */
  
#define BS            0x08	/* Backspace */
#define CR            0x0d	/* Carriage return */
#define ESC           0x1b	/* Escape */
  
/*
 *    My Flags. These are global to all windows, not window specific.
 */

#define CFLAG_CURSOR    0001	/* T=Cursor on, F=Cursor off. */
#define CFLAG_CBREAK    0002	/* T=cbreak mode, F=nocbreak mode */
#define CFLAG_NLCR      0004	/* T=nl to cr mapping, F=no mapping */
#define CFLAG_ECHO      0010	/* T=Echo enabled, F=no echo */
#define CFLAG_INITSCR   0020	/* T=initscr has been called */
#define CFLAG_KEYPAD    0040	/* T=translate ANSI codes to special ints */

/*
 *    WINDOW flags, these are specific to each window.
 */

#define CWF_MOVED    0001	/* move() has been done on this window */

/*
 *    Buffer size for raw key events.
 */
#define RAWBUFSIZ    32

/*
 *    Scroll directions
 */
#define SCROLL_UP    1
#define SCROLL_DOWN  2

/*
 *    Simple implementation of wnoutrefresh() and doupdate()
 */

struct RefreshElement {
  WINDOW *WinPtr;
  struct RefreshElement *Next;
};


/*
 * Externals in _data.c
 */
extern unsigned char CursesFlags;
extern int CursesType;
extern unsigned char GetchNChars, GetchBufPos;
extern short CursorCol, CursorLine, LCursorLine, LCursorCol;
extern struct WindowState *HeadWindowList;
extern struct RefreshElement *HeadRefreshList;
extern struct RastPort *RPort;
extern struct ViewPort *VPort;
extern struct IntuitionBase *IntuitionBase;
extern struct GfxBase *GfxBase;
extern struct IOStdReq ioreq;
extern struct Screen *CursesScreen;
extern struct Window *CursesWindow;
extern int FontHeight, FontWidth, FontBase;
extern struct FileHandle *ifh;


/*
 * Prototypes.
 */

void DoEcho(WINDOW *, char);
int Scroll(WINDOW *, int, int, int);
void CleanExit(int);
void ZapCursor(void);
void DrawCursor(void);
void ToggleCursor(int, int);
void CleanUp(void);
/* Prototypes for functions defined in _ansi.c */
void ANSIClear(void);
void ANSIMove(int line, int col);
void ANSIFlash(void);
void ANSIClearRect(int line, int col, int height, int width);
