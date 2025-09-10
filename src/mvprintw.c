/*
 *
 *
 * Filename : mvprintw.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Move then print.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: mvprintw.c,v $
 * Revision 1.1  1991/09/07  11:44:10  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/mvprintw.c,v 1.1 1991/09/07 11:44:10 sie Exp $";

#include "curses.h"
#include <stdarg.h>


int mvprintw(int Line, int Col, char *fmt, ...)
{
  int Ret;
  char buffer[BUFSIZ];
  va_list ap;

  va_start(ap, fmt);
  Ret = vsprintf(buffer, fmt, ap);
  wmove(stdscr, Line, Col);
  waddstr(stdscr, buffer);
  return Ret;
}
