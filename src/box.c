/*
 *
 *
 * Filename : box.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Draw a box around window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: box.c,v $
 * Revision 1.1  1991/09/07  11:40:10  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/box.c,v 1.1 1991/09/07 11:40:10 sie Exp $";

#include "acurses.h"


box(WINDOW *WinPtr, char vert, char hor)
{
  int i;
  short CurY, CurX;
  
  CurY = WinPtr->_cury;
  CurX = WinPtr->_curx;
  
  if(vert < 32 || vert > 126)
    vert = '|';
  if(hor < 32 || hor > 126)
    hor = '-';
  
  for(i=0; i<=WinPtr->_maxx; i++) {
    mvwaddch(WinPtr, 0, i, hor);  /* Top horizontal */
    mvwaddch(WinPtr, WinPtr->_maxy, i, hor);  /* Bottom horizontal */
  }
  for(i=1; i<WinPtr->_maxy; i++) {
    mvwaddch(WinPtr, i, 0, vert);  /* Left vertical */
    mvwaddch(WinPtr, i, WinPtr->_maxx, vert);  /* Right vertical */
  }
  WinPtr -> _cury = CurY;
  WinPtr -> _curx = CurX;
  return OK;
}
