/*
 *
 *
 * Filename : endwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Finished with curses, close everything and return.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: endwin.c,v $
 * Revision 1.4  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.3  1992/06/10  23:44:36  sie
 * Added serial support.
 *
 * Revision 1.2  91/12/26  14:40:27  sie
 * removed use of Next and Prev in WinStat as linked list is no longer
 * relevant.
 * 
 * Revision 1.1  91/09/07  11:41:32  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/endwin.c,v 1.4 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


/*
 *  Close the screen and libraries.
 */

int endwin(void)                  /* called from main prior to exit. */
{
  if(!(_CursesFlags & CFLAG_INITSCR)) {  /* haven't called initscr() */
    return ERR;
  }
  _CleanUp();
  _CursesFlags &= ~CFLAG_INITSCR;  /* Mark that we have called endwin() */
  if(_CursesType == ANSI_CURSES)
    _ANSIMove(LINES-1, 0);
  if(_CursesFlags & CFLAG_CBREAK)
    nocbreak();
  return OK;
}
