/*
 *
 *
 * Filename : waddch.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Adds a single char to the display buffer.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: waddch.c,v $
 * Revision 1.1  1991/09/07  11:48:54  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/waddch.c,v 1.1 1991/09/07 11:48:54 sie Exp $";

#include "curses.h"


int waddch(WINDOW *WinPtr, char c)
{
  char *str = " ";
  
  *str = c;
  return waddstr(WinPtr, str);
}
