/*
 *
 *
 * Filename : werase.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Empties the screen buffer.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: werase.c,v $
 * Revision 1.4  1993/05/17  23:28:16  sie
 * Underscores added to names.
 *
 * Revision 1.3  1991/12/30  10:31:21  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 *
 * Revision 1.2  91/12/28  14:01:21  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.1  91/09/07  11:50:02  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/werase.c,v 1.4 1993/05/17 23:28:16 sie Exp $";

#include "acurses.h"


werase(WINDOW *WinPtr)
{
  int Line;
  
  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  /* Blank screen image */
  for(Line=0; Line<WinPtr->NLines; Line++) {
    memset(WinPtr->LnArry[Line].Line, ' ', WinPtr->_maxx + 1);
    memset(WinPtr->LnArry[Line].ATTRS, WinPtr->_attrs, WinPtr->_maxx+1);
    WinPtr->LnArry[Line].Touched = TRUE;
    WinPtr->LnArry[Line].StartCol = 0;
    WinPtr->LnArry[Line].EndCol = WinPtr->_maxx;
  }
  WinPtr->_curx = 0;
  WinPtr->_cury = 0;
  return OK;
}
