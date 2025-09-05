/* -*-C-*-
 *
 *
 * Filename : _data.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.bt.co.uk).
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Internal data.
 *
 *
 * THIS CODE IS NOT PUBLIC DOMAIN
 * ==============================
 * 
 * This code is copyright Simon J Raybould 1991, all rights are reserved.
 * All code, ideas, data structures and algorithms remain the property of the
 * author. Neither the whole nor sections of this code may be used as part
 * of other code without the authors consent. If you wish to use some of this
 * code then please email me at (sie@fulcrum.bt.co.uk).
 *
 * This source is not public domain, so you do not have any right to alter it
 * or sell it for personal gain. The source is provided purely for reference
 * purposes. You may re-compile the source with any compiler you choose.
 * You must not distribute altered copies without the authors consent. My
 * intention is that the source will help people isolate any bugs much more
 * effectivly.
 *
 * Disclaimer
 * ==========
 *
 * No implication is made as to this code being fit for any purpose at all.
 * I (the author) shall not be held responsible for any loss of data or damage 
 * to property that may result from its use or misuse.
 *
 *
 * Revision History
 * ================
 *
 * $Log:	_data.c,v $
 * Revision 1.5  92/06/10  23:45:09  sie
 * Added serial support.
 * 
 * Revision 1.4  92/01/25  23:56:54  sie
 * added FontHeight and FontWidth.
 * 
 * Revision 1.3  91/12/30  11:52:48  sie
 * default DEPTH now 1.
 * 
 * Revision 1.2  91/12/28  22:46:17  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.1  91/09/07  11:52:52  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: SRC:lib/curses/src/RCS/_data.c,v 1.5 92/06/10 23:45:09 sie Exp $";

#include "acurses.h"

/*
 * Should initialise all of these to NULL to be certain that
 * CleanExit() will function correctly. Most compilers will do this
 * anyway, but better safe than GURUed.
 */

struct IntuitionBase *IntuitionBase = NULL;
struct GfxBase *GfxBase = NULL;

struct Library *ConsoleDevice = NULL;
struct IOStdReq ioreq;
struct Screen *CursesScreen = NULL;
struct Window *CursesWindow = NULL;

struct RastPort *RPort = NULL;
struct ViewPort *VPort = NULL;
struct FileHandle *ifh = NULL;

BYTEBITS CursesFlags = CFLAG_ECHO | CFLAG_NLCR | CFLAG_CURSOR;
int CursesType = CUST_CURSES;	/* default to use graphics library */

short CursorCol = 0, CursorLine = 0, LCursorLine = -1, LCursorCol = -1;
struct WindowState *HeadWindowList = (struct WindowState *)NULL;
struct RefreshElement *HeadRefreshList=(struct RefreshElement *)NULL;

WINDOW *stdscr = (WINDOW *)NULL, *curscr = (WINDOW *)NULL;
int LINES=24, COLS=80, DEPTH=1;  /* Defaults */
int FontHeight, FontWidth, FontBase;


/*
 *  Need to be global so that flushinp() can reset them !
 */
unsigned char GetchNChars=0, GetchBufPos=0;
