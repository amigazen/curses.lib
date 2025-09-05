/*
 *
 *
 * Filename : delwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Frees up memory used by a window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: delwin.c,v $
 * Revision 1.6  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.5  1992/06/10  23:44:34  sie
 * Added serial support.
 *
 * Revision 1.4  91/12/30  10:30:55  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 * 
 * Revision 1.3  91/12/28  13:57:24  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.2  91/12/26  14:39:45  sie
 * removed use of Next and Prev in WinStat as linked list is no longer
 * relevant.
 * 
 * Revision 1.1  91/09/07  11:40:51  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/delwin.c,v 1.6 1993/05/17 23:33:10 sie Exp $";

#include <stdlib.h>
#include "acurses.h"


delwin(WINDOW *WinPtr)
{
  int LineNo;
  
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  if(!WinPtr->ParentWin) {
    /* If it's a real window, free up Line, ATTRS */
    for(LineNo=0; LineNo<WinPtr->NLines; LineNo++) {
      free(WinPtr->LnArry[LineNo].Line);
      free(WinPtr->LnArry[LineNo].ATTRS);
    }
  }
  /* Free up LnArry[] */
  free(WinPtr->LnArry);
  /* Free the WinPtr */
  free(WinPtr);
  return OK;
}
