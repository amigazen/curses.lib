/*
 *
 *
 * Filename : wdeleteln.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Delete line, all lines below are scrolled up.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wdeleteln.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:49:57  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wdeleteln.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


wdeleteln(WINDOW *WinPtr)
{
  _Scroll(WinPtr, WinPtr->_cury, WinPtr->_maxy, SCROLL_UP);
  return OK;
}
