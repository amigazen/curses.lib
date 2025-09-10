/*
 *
 *
 * Filename : mvwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Moves a window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: mvwin.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:44:27  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/mvwin.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int mvwin(WINDOW *WinPtr, int NewLine, int NewCol)
{
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  WinPtr->_begx = NewCol;
  WinPtr->_begy = NewLine;
  if(touchwin(WinPtr) == ERR)
    return ERR;
  return OK;
}
