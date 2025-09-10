/*
 *
 *
 * Filename : initcolour.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Sets a colour register.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: initcolour.c,v $
 * Revision 1.4  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.3  1992/06/10  23:44:39  sie
 * Added serial support.
 *
 * Revision 1.2  91/09/28  18:33:17  sie
 * DEPTH instead on NPLANES.
 * 
 * Revision 1.1  91/09/07  11:43:26  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/initcolour.c,v 1.4 1993/05/17 23:33:10 sie Exp $";

#include <exec/types.h>
#include "acurses.h"


init_color(WORD n, UWORD r, UWORD g, UWORD b)
{
  if(n<0 || n>=(1<<DEPTH) || r>1000 || g>1000 || b>1000)
    return ERR;
  if(_CursesType == CUST_CURSES)
    SetRGB4(_VPort, n, r*15/1000, g*15/1000, b*15/1000);
  return OK;
}
