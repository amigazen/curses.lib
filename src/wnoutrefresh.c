/*
 *
 *
 * Filename : wnoutrefresh.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Refresh without output.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wnoutrefresh.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1992/06/10  23:45:03  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:51:53  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wnoutrefresh.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include <stdlib.h>
#include "acurses.h"

wnoutrefresh(WINDOW *WinPtr)
{
  struct RefreshElement *NewRefEl;
  
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  if(!(NewRefEl = (struct RefreshElement *)
       malloc(sizeof(struct RefreshElement))))
    return ERR;
  
  /* Fill the new element in */
  NewRefEl->Next = (struct RefreshElement *)NULL;
  NewRefEl->WinPtr = WinPtr;
  
  /* Add to start of refresh list */
  if(_HeadRefreshList)
    NewRefEl->Next = _HeadRefreshList;
  _HeadRefreshList = NewRefEl;
}
