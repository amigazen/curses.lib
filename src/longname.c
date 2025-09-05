/*
 *
 *
 * Filename : SRC:lib/curses/src/longname.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Wed Jan 20 22:20:45 1993
 *
 * Desc     : Gets the longname for your terminal.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Revision History
 * ================
 *
 * $Log: longname.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/longname.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include "acurses.h"

char *
longname(char *termbuf, char *name)
{
  /* Should extract terminal name from termbuf */
  if(_CursesType == CUST_CURSES)
    strcpy(name, "Amiga custom");
  else
    strcpy(name, "Amiga ANSI"); /* This will do for now */

  return name;
}
