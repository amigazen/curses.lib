/*
 *
 *
 * Filename : touchwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Makes whole window in need of a refresh.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: touchwin.c,v $
 * Revision 1.4  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.3  1991/12/30  10:31:07  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 *
 * Revision 1.2  91/12/28  14:00:55  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.1  91/09/07  11:48:40  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/touchwin.c,v 1.4 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


touchwin(WINDOW *WinPtr)
{
  int Line;
  
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  for(Line=0; Line<WinPtr->NLines; Line++) {
    WinPtr->LnArry[Line].Touched = TRUE;
    /* Mark whole line as refreshable */
    WinPtr->LnArry[Line].StartCol = 0;
    WinPtr->LnArry[Line].EndCol = WinPtr->_maxx;
  }
  return OK;
}
