/*
 *
 *
 * Filename : SRC:lib/curses/src/setupterm.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Thu Jun 24 21:20:37 1993
 *
 * Desc     : Initialisation for terminfo support.
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
 * $Log: setupterm.c,v $
 * Revision 1.1  1994/02/21  22:18:22  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/setupterm.c,v 1.1 1994/02/21 22:18:22 sie Exp $";
#endif /* lint */

#include "acurses.h"


static char __sut_bp[1024], __sut_area[1024], *aptr = __sut_area;


void
setupterm(void)
{
  char *lterm;                  /* The terminal type */
  
  if(!(lterm = getenv("TERM"))) {
    fprintf(stderr, "Failed to get terminal type\n");
    return;                     /* don't know term type */
  }  
    
  tgetent(__sut_area, lterm);

  /* get clear capability string */
  _clstr = aptr;
  if(!tgetstr("cl", &aptr))
    fprintf(stderr, "Failed to get cl string\n");

  /* get cursor motion capability string */
  _cmstr = aptr;
  if(!tgetstr("cm", &aptr))
    fprintf(stderr, "Failed to get cm string\n");
}
