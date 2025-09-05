/*
 *
 *
 * Filename : Workbench2.0:src/curses/_mergewin.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Sat Feb 06 19:39:15 1993
 *
 * Desc     : _mergewin(win1, win2, flag) used to implement overlay() and overwrite().
 *            if flag is TRUE then copy spaces else miss them out.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Revision History
 * ================
 *
 * $Log: _mergewin.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_mergewin.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include "curses.h"

_mergewin(WINDOW *win1, WINDOW *win2, char flag)
{
  return OK;
}
