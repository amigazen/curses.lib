/*
 *
 *
 * Filename : nonl.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Stop NL to NLCR mapping.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: nonl.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:45:47  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/nonl.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


nonl(void)
{
  _CursesFlags &= ~CFLAG_NLCR;
  return OK;
}
