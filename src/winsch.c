/*
 *
 *
 * Filename : winsch.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Inserts a character into the screen buffer.
 *            All char to the right are slid along to make room.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: winsch.c,v $
 * Revision 1.2  1991/12/28  14:01:31  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 *
 * Revision 1.1  91/09/07  11:50:31  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/winsch.c,v 1.2 1991/12/28 14:01:31 sie Exp $";

#include "acurses.h"


int winsch(WINDOW *WinPtr, char c)
{
  int i;
  
  /* shuffle line along to the right */
  for (i = WinPtr->_maxx; i > WinPtr->_curx; i--)
    WinPtr->LnArry[WinPtr->_cury].Line[i] = WinPtr->LnArry[WinPtr->_cury].Line[i-1];
  WinPtr->LnArry[WinPtr->_cury].Line[i] = c;
  WinPtr->LnArry[WinPtr->_cury].StartCol = min(WinPtr->LnArry[WinPtr->_cury].StartCol, WinPtr->_curx);
  WinPtr->LnArry[WinPtr->_cury].EndCol = WinPtr->_maxx;
  WinPtr->LnArry[WinPtr->_cury].Touched = TRUE;
  
  return OK;
}
