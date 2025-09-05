/*
 *
 *
 * Filename : nodelay.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Stops getch() blocking for input.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: nodelay.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:45:21  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/nodelay.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


nodelay(WINDOW *WinPtr, int flag)
{
  if(!WinPtr)
    return ERR;
  
  WinPtr->_nodelay = flag ? TRUE : FALSE;
  return OK;
}
