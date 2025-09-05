/*
 *
 *
 * Filename : mvwprintw.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Move and print in a particullar window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: mvwprintw.c,v $
 * Revision 1.1  1991/09/07  11:44:33  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/mvwprintw.c,v 1.1 1991/09/07 11:44:33 sie Exp $";

#include "acurses.h"
#include <stdarg.h>


int mvwprintw(WINDOW *WinPtr, int Line, int Col, char *fmt, ...)
{
  int Ret;
  char buffer[BUFSIZ];
  va_list ap;
  
  va_start(ap, fmt);
  Ret = vsprintf(buffer, fmt, ap);
  wmove(WinPtr, Line, Col);
  waddstr(WinPtr, buffer);
  return Ret;
}
