/*
 *
 *
 * Filename : hascolours.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Returns TRUE if we have colours.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: hascolours.c,v $
 * Revision 1.2  1991/09/28  18:32:54  sie
 * DEPTH instead on NPLANES.
 *
 * Revision 1.1  91/09/07  11:42:52  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/hascolours.c,v 1.2 1991/09/28 18:32:54 sie Exp $";

#include "acurses.h"


has_colors(void)
{
  if(DEPTH>1)
    return TRUE;		/* Yes baby we have colours */
  else
    return FALSE;
}
