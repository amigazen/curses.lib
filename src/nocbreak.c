/*
 *
 *
 * Filename : nocbreak.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Leave cbreak mode.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: nocbreak.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:44:46  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:45:05  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/nocbreak.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


nocbreak(void)
{
  if(_CursesType == ANSI_CURSES && _ifh)
    _CanonMode(_ifh);
  
  _CursesFlags &= ~CFLAG_CBREAK;
  return OK;
}
