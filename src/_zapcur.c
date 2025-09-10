/*
 *
 *
 * Filename : _zapcur.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Remove cursor from screen.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _zapcur.c,v $
 * Revision 1.2  1993/05/17  23:28:52  sie
 * Underscores added to names.
 *
 * Revision 1.1  1991/09/07  11:53:36  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_zapcur.c,v 1.2 1993/05/17 23:28:52 sie Exp $";

#include "acurses.h"


void
_ZapCursor(void)
{
  /* If there was a cursor then blank it */
  if(_LCursorCol >= 0 && _LCursorLine >= 0)
    _ToggleCursor(_LCursorLine, _LCursorCol);
  
  _LCursorCol = _LCursorLine = -1;
}
