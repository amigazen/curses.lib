/*
 *
 *
 * Filename : wgetstr.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Read a string from the keyboard, provide del facility.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wgetstr.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:45:00  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:50:18  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wgetstr.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


int wgetstr(WINDOW *WinPtr, char *ptr)
{
  char done = FALSE, *BuffStart;
  unsigned char CbreakSet;  /* Used to restore after */
  
  if(!(_CursesFlags & CFLAG_INITSCR))  /* Haven't called initscr() */
    return ERR;
  
  BuffStart = ptr;
  
  /* Will need to be in CBREAK mode for this */
  CbreakSet = _CursesFlags & CFLAG_CBREAK;
  cbreak();
  while(!done) {
    switch(*ptr = wgetch(WinPtr)) {
    case -1:  /* wgetch() returned ERROR */
      *ptr = '\0';
      if(!CbreakSet)		/* if wasn't set then unset cbreak */
	nocbreak();
      return -1;
    case '\n':
    case '\r':
      *ptr = '\0';
      done = TRUE;
      break;
    case '\b':
      if(--ptr < BuffStart)  /* Don't move before start */
	ptr = BuffStart;
      else if(_CursesFlags & CFLAG_ECHO) {
	/* Do BS SP BS processing */
	mvcur(_CursorLine, _CursorCol, _CursorLine, _CursorCol - 1);  /* BS */
	_DoEcho(WinPtr, ' ');          /* SP */
	mvcur(_CursorLine, _CursorCol, _CursorLine, _CursorCol - 1);  /* BS */
      }
      break;
    default:
      ptr++;
      break;
    }
  }
  if(!CbreakSet)		/* if wasn't set then unset cbreak */
    nocbreak();
  return 0;
}
