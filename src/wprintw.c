/*
 *
 *
 * Filename : wprintw.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Curses printf().
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wprintw.c,v $
 * Revision 1.1  1991/09/07  11:52:03  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wprintw.c,v 1.1 1991/09/07 11:52:03 sie Exp $";

#include "acurses.h"
#include <stdarg.h>


wprintw(WINDOW *WinPtr, char *fmt, ...)
{
  int Ret;
  char buffer[BUFSIZ];
  va_list ap;
  
  va_start(ap, fmt);
  Ret = vsprintf(buffer, fmt, ap);
  waddstr(WinPtr, buffer);
  return Ret;
}
