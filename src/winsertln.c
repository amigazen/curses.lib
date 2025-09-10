/*
 *
 *
 * Filename : winsertln.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Insert a line, scroll all lines below down one.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: winsertln.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:51:41  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/winsertln.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


winsertln(WINDOW *WinPtr)
{
  _Scroll(WinPtr, WinPtr->_cury, WinPtr->_maxy, SCROLL_DOWN);
  return OK;
}
