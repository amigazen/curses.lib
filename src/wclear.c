/*
 *
 *
 * Filename : wclear.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Clears the display.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wclear.c,v $
 * Revision 1.5  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.4  1991/12/30  10:31:18  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 *
 * Revision 1.3  91/12/28  22:45:35  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.2  91/12/28  14:01:10  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.1  91/09/07  11:49:29  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wclear.c,v 1.5 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int wclear(WINDOW *WinPtr)
{
  int Line;
  
  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  for(Line=0; Line<WinPtr->NLines; Line++) {
    memset(WinPtr->LnArry[Line].Line, ' ', WinPtr->_maxx + 1);
    memset(WinPtr->LnArry[Line].ATTRS, WinPtr->_attrs, WinPtr->_maxx+1);
    WinPtr->LnArry[Line].Touched = FALSE;
    WinPtr->LnArry[Line].StartCol = WinPtr->_maxx+1;
    WinPtr->LnArry[Line].EndCol = 0;
  }
  WinPtr->_curx = 0;
  WinPtr->_cury = 0;
  WinPtr->_clear = TRUE;
  return OK;
}
