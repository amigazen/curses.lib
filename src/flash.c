/*
 *
 *
 * Filename : flash.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Flashes the screen.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: flash.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:44:37  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:41:54  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/flash.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


flash(void)
{
  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  if(_CursesType == CUST_CURSES)
    DisplayBeep(_CursesScreen);
  if(_CursesType == ANSI_CURSES)
    _ANSIFlash();
  
  return OK;
}
