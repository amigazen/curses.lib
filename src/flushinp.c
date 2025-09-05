/*
 *
 *
 * Filename : flushinp.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Empty keyboard buffer.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: flushinp.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1991/12/28  22:43:56  sie
 * changed attrs to UBYTE from short + some tidying up.
 *
 * Revision 1.1  91/09/07  11:42:01  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/flushinp.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


flushinp(void)
{
  _GetchBufPos = 0;
  _GetchNChars = 0;
  return OK;
}
