/*
 *
 *
 * Filename : winch.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Reads char at current screen position.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: winch.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1991/12/28  14:01:29  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 *
 * Revision 1.1  91/09/07  11:50:24  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/winch.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int winch(WINDOW *WinPtr)
{
  if(!WinPtr)
    return ERR;
  
  return (int)WinPtr->LnArry[WinPtr->_cury].Line[WinPtr->_curx];
}
