/*
 *
 *
 * Filename : _drawcur.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Draw cursor.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _drawcur.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:45:14  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:53:05  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_drawcur.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


void
_DrawCursor(void)
{
  if(_CursesType == ANSI_CURSES)
    mvcur(_LCursorLine, _LCursorCol, _CursorLine, _CursorCol);
  else {
    /* Draw cursor */
    if(_CursesFlags & CFLAG_CURSOR)
      _ToggleCursor(_CursorLine, _CursorCol);
    
    if(_CursesFlags & CFLAG_CURSOR) {
      _LCursorCol = _CursorCol;
      _LCursorLine = _CursorLine;
    } else {
      _LCursorCol = -1;
      _LCursorLine = -1;
    }
  }
}
