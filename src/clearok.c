/*
 *
 *
 * Filename : clearok.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Makes it legal to clear the screen on next refresh.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: clearok.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:40:40  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/clearok.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


clearok(WINDOW *WinPtr, int flag)
{
  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  WinPtr->_clear = (flag) ? TRUE : FALSE;
  
  return OK;
}
