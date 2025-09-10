/*
 *
 *
 * Filename : scroll.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Scrolls the screen up one line.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: scroll.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1991/12/28  14:00:44  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 *
 * Revision 1.1  91/09/07  11:46:39  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/scroll.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


scroll(WINDOW *WinPtr)
{
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  _Scroll(WinPtr, WinPtr->ScrollTop, WinPtr->ScrollBot, SCROLL_UP);
  return OK;
}
