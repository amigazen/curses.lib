/*
 *
 *
 * Filename : wdelch.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Deletes the char at the current location in the buffer.
 *            All chars to the right are slid left to fill the gap.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wdelch.c,v $
 * Revision 1.2  1991/12/28  14:01:16  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 *
 * Revision 1.1  91/09/07  11:49:51  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wdelch.c,v 1.2 1991/12/28 14:01:16 sie Exp $";

#include "acurses.h"


int wdelch(WINDOW *WinPtr)
{
  int i;
  
  /* shuffle line along to the left */
  for (i = WinPtr->_curx; i < WinPtr->_maxx; i++)
    WinPtr->LnArry[WinPtr->_cury].Line[i] = WinPtr->LnArry[WinPtr->_cury].Line[i+1];
  WinPtr->LnArry[WinPtr->_cury].Line[i] = ' ';  /* Blank last char */
  WinPtr->LnArry[WinPtr->_cury].StartCol = min(WinPtr->LnArry[WinPtr->_cury].StartCol, WinPtr->_curx);
  WinPtr->LnArry[WinPtr->_cury].EndCol = WinPtr->_maxx;
  WinPtr->LnArry[WinPtr->_cury].Touched = TRUE;
  
  return OK;
}
