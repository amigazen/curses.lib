/*
 *
 *
 * Filename : _exit.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : CleanExit code.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _exit.c,v $
 * Revision 1.2  1993/05/17  23:30:51  sie
 * Underscores added to names.
 * ,
 *
 * Revision 1.1  1991/09/07  11:53:11  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_exit.c,v 1.2 1993/05/17 23:30:51 sie Exp $";

#include "acurses.h"


void
_CleanExit(int RetCode)
{
  _CleanUp();
  exit(RetCode);
}
