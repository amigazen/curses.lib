/*
 *
 *
 * Filename : doupdate.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Send output from previous wnoutrefresh calls.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: doupdate.c,v $
 * Revision 1.3  1993/05/17  23:32:24  sie
 * Underscores added to names.
 *
 * Revision 1.2  1992/06/10  23:44:35  sie
 * Added serial support.
 *
 * Revision 1.1  91/09/07  11:41:07  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/doupdate.c,v 1.3 1993/05/17 23:32:24 sie Exp $";

#include <stdlib.h>
#include "acurses.h"


static void ZapRElList(struct RefreshElement *ElPtr)
{
  if(!ElPtr)
    return;
  if(ElPtr->Next)
    ZapRElList(ElPtr->Next);  /* Recurse my boy */
  free(ElPtr);
}

doupdate(void)
{
  struct RefreshElement *ElPtr;
  
  if(!(_CursesFlags & CFLAG_INITSCR))
    return ERR;
  
  ElPtr = _HeadRefreshList;
  while(ElPtr) {
    if(wrefresh(ElPtr->WinPtr) == ERR)
      return ERR;
    ElPtr = ElPtr->Next;
  }
  ZapRElList(_HeadRefreshList);
  _HeadRefreshList = (struct RefreshElement *)NULL;
  
  return OK;
}
