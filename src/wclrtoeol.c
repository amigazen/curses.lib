/*
 *
 *
 * Filename : wclrtoeol.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Clear to end of line.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wclrtoeol.c,v $
 * Revision 1.4  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.3  1992/06/23  22:14:06  sie
 * Changed from a for loop to memset(), should be quicker.
 *
 * Revision 1.2  92/06/21  01:13:20  sie
 * Now writes directly to the screen structure rather than
 * using waddstr and wmove.
 * 
 * Revision 1.1  91/09/07  11:49:45  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wclrtoeol.c,v 1.4 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


wclrtoeol(WINDOW *WinPtr)
{
  if(!(_CursesFlags & CFLAG_INITSCR)) /* Haven't called initscr() */
    return ERR;

  memset(&(WinPtr->LnArry[WinPtr->_cury].Line[WinPtr->_curx]),
	 ' ', WinPtr->_maxx-WinPtr->_curx+1);
  memset(&(WinPtr->LnArry[WinPtr->_cury].ATTRS[WinPtr->_curx]),
	 WinPtr->_attrs, WinPtr->_maxx-WinPtr->_curx+1);

  WinPtr->LnArry[WinPtr->_cury].StartCol =
    min(WinPtr->_curx, WinPtr->LnArry[WinPtr->_cury].StartCol);
  WinPtr->LnArry[WinPtr->_cury].EndCol = WinPtr->_maxx;
  WinPtr->LnArry[WinPtr->_cury].Touched = TRUE;
  return OK;
}
