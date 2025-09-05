/*
 *
 *
 * Filename : _data.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Internal data.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _data.c,v $
 * Revision 1.7  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.6  1992/12/25  23:40:50  sie
 * GNU C port.
 *
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

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_data.c,v 1.7 1993/05/17 23:33:10 sie Exp $";

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
struct Screen *_CursesScreen = NULL;
struct Window *_CursesWindow = NULL;
struct MsgPort *_CursesMsgPort = NULL;

struct RastPort *_RPort = NULL;
struct ViewPort *_VPort = NULL;
BPTR _ifh = NULL;

BYTEBITS _CursesFlags = CFLAG_ECHO | CFLAG_NLCR | CFLAG_CURSOR;
int _CursesType = CUST_CURSES;	/* default to use graphics library */

int _CursorCol = 0, _CursorLine = 0, _LCursorLine = -1, _LCursorCol = -1;
struct RefreshElement *_HeadRefreshList=(struct RefreshElement *)NULL;

WINDOW *stdscr = (WINDOW *)NULL, *curscr = (WINDOW *)NULL;
int LINES=24, COLS=80, DEPTH=1;  /* Defaults */
int _FontHeight=8, _FontWidth=8, _FontBase=6; /* defaults for topaz 8 */


/*
 *  Need to be global so that flushinp() can reset them.
 */
unsigned char _GetchNChars=0, _GetchBufPos=0;

/*
 * termcap stuff.
 */
char *__area;                   /* need to remember where the users buffer is */
char *__capary[MAX_CAPS];       /* array of pointers to capabilities */
int __no_caps = 0;              /* number of capabilities */

/*
 * data for ANSI curses.
 */
char *_clstr;                    /* clear screen capability */
char *_cmstr;                    /* cursor motion capability */
