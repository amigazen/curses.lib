/*
 *
 *
 * Filename : scrollok.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Switches whether or not to scroll when the bottom is hit.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: scrollok.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:46:48  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/scrollok.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


scrollok(WINDOW *WinPtr, int flag)
{
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  WinPtr->_scroll = (flag) ? TRUE : FALSE;
  return OK;
}
