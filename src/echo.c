/*
 *
 *
 * Filename : echo.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Enables screen echo.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: echo.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:41:26  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/echo.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"

echo(void)
{
  _CursesFlags |= CFLAG_ECHO;
  return OK;
}
