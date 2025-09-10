/*
 *
 *
 * Filename : Workbench2.0:src/curses/overwrite.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Sat Feb 06 19:30:24 1993
 *
 * Desc     : Overwrite one window on top of another.
 *            Do copy the spaces.
 *
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: overwrite.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/overwrite.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include "curses.h"

overwrite(WINDOW *win1, WINDOW *win2)
{
  return _mergewin(win1, win2, TRUE);
}
