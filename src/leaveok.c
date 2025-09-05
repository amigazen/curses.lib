/*
 *
 *
 * Filename : leaveok.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Removes the cursor.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: leaveok.c,v $
 * Revision 1.2  1993/05/17  23:24:55  sie
 * Minor changes to names and stuff.
 *
 * Revision 1.1  1991/09/07  11:43:56  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/leaveok.c,v 1.2 1993/05/17 23:24:55 sie Exp $";

#include "acurses.h"


leaveok(WINDOW *WinPtr, int flag)
{
  if(!(_CursesFlags & CFLAG_INITSCR)) /* Haven't called initscr() */
    return ERR;
  
  if(flag) {
    _CursorCol = _CursorLine = -1;
    _CursesFlags &= ~CFLAG_CURSOR;
  } else {
    _CursesFlags |= CFLAG_CURSOR;
  }
  return OK;
}
