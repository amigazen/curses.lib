/*
 *
 *
 * Filename : idlok.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Enable hardware insert/delete line.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: idlok.c,v $
 * Revision 1.1  1991/09/07  11:43:09  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/idlok.c,v 1.1 1991/09/07 11:43:09 sie Exp $";

#include "acurses.h"


idlok(WINDOW *WinPtr, int flag)
{
  /* This function is to enable hardware insert/delete line */
  return OK;
}
