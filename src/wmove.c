/*
 *
 *
 * Filename : wmove.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Moves the cursor.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wmove.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:51:45  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wmove.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int wmove(WINDOW *WinPtr, int Line, int Col)
{
  if(!WinPtr)
    return ERR;
  
  if(Line<0 || Line>WinPtr->_maxy)
    return ERR;
  if(Col<0 || Col>WinPtr->_maxx)
    return ERR;
  WinPtr -> _cury = Line;
  WinPtr -> _curx = Col;
  WinPtr -> _flags |= CWF_MOVED;
  return OK;
}
