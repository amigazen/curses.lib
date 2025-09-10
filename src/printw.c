/*
 *
 *
 * Filename : printw.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : printf()
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: printw.c,v $
 * Revision 1.1  1991/09/07  11:45:59  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/printw.c,v 1.1 1991/09/07 11:45:59 sie Exp $";

#include "curses.h"
#include <stdarg.h>


printw(char *fmt, ...)
{
  int Ret;
  char buffer[BUFSIZ];
  va_list ap;
  
  va_start(ap, fmt);
  Ret = vsprintf(buffer, fmt, ap);
  waddstr(stdscr, buffer);
  return Ret;
}
