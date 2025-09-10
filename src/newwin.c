/*
 *
 *
 * Filename : newwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Creat a new window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: newwin.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/12/25  23:36:56  sie
 * GNU C port.
 *
 * Revision 1.1  91/09/07  11:44:45  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/newwin.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


WINDOW *newwin(unsigned int NLines,
               unsigned int NCols,
               unsigned int StartLine,
               unsigned int StartCol)
{
  WINDOW *WinPtr;
  
  if(!(WinPtr = (WINDOW *) _CreatWindow(NLines, NCols, StartLine, StartCol, NULL))) {
    printf("WARNING - newwin() failed, returning stdscr !!\n");
    return stdscr;  /* Failed */
  }
  wclear(WinPtr);
  return WinPtr;
}
