/*
 *
 *
 * Filename : wsetscrreg.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Sets scrolling region.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wsetscrreg.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1991/12/28  14:01:47  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 *
 * Revision 1.1  91/09/07  11:52:17  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wsetscrreg.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int wsetscrreg(WINDOW *WinPtr, int top, int bottom)
{
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  WinPtr->ScrollTop = top;
  WinPtr->ScrollBot = bottom;
  return OK;
}
