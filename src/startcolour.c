/*
 *
 *
 * Filename : startcolour.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Init to start using colours.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: startcolour.c,v $
 * Revision 1.2  1991/12/30  11:52:27  sie
 * This now sets DEPTH to 3.
 *
 * Revision 1.1  91/09/07  11:47:04  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/startcolour.c,v 1.2 1991/12/30 11:52:27 sie Exp $";

#include "curses.h"


start_color(void)
{
  DEPTH=3;
  return OK;			/* No init required to get colours going */
}
