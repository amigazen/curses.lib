/*
 *
 *
 * Filename : wstandend.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Leave standout mode, returnign to normal video.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wstandend.c,v $
 * Revision 1.2  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.1  1991/09/07  11:52:24  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wstandend.c,v 1.2 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


wstandend(WINDOW *WinPtr)
{
  if(!WinPtr)
    return ERR;
  
  WinPtr->_attrs &= ~A_STANDOUT;
}
