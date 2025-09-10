/*
 *
 *
 * Filename : _togcur.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Toggle the cursor on/off.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _togcur.c,v $
 * Revision 1.4  1993/05/17  23:30:32  sie
 * Underscores added to names.
 *
 * Revision 1.3  1992/06/10  23:45:17  sie
 * Added serial support.
 *
 * Revision 1.2  92/01/25  23:57:26  sie
 * Now uses FontHeight and FontWidth.
 * 
 * Revision 1.1  91/09/07  11:53:30  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_togcur.c,v 1.4 1993/05/17 23:30:32 sie Exp $";

#include "acurses.h"


void
_ToggleCursor(int Line, int Col)
{
  if(_CursesType == CUST_CURSES) {
    SetDrMd(_RPort, JAM2 | INVERSVID | COMPLEMENT);
    Move(_RPort, Col*_FontWidth, _FontBase+Line*_FontHeight);
    Text(_RPort, " ", 1);
  }
}
