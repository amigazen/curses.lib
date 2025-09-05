/*
 *
 *
 * Filename : baud.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Return baud rate. Some programs such as "vi" use this to
 *            decide if they should limit the number of lines displayed.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: baudrate.c,v $
 * Revision 1.1  1991/09/07  11:37:58  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/baudrate.c,v 1.1 1991/09/07 11:37:58 sie Exp $";

#include "acurses.h"


baudrate(void)
{
  return 19200;       /* This should be fast enough */
}
