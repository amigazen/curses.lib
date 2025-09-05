/*
 *
 *
 * Filename : mvcur.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Move the cursor.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: mvcur.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:44:44  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:44:04  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/mvcur.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


mvcur(int CurLine, int CurCol, int NewLine, int NewCol)
{
  if(_CursesType == CUST_CURSES) {
    /* Could check CurLine and CurCol but this would make it fail too often */
    _ZapCursor();
    _CursorLine = NewLine;
    _CursorCol = NewCol;
    _DrawCursor();
  } else {
    _ANSIMove(NewLine, NewCol);
    _CursorLine = NewLine;
    _CursorCol = NewCol;
  }
  return OK;
}
