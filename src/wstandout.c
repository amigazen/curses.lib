/*
 *
 *
 * Filename : wstandout.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Enter standout mode (INVERSE)
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wstandout.c,v $
 * Revision 1.1  1991/09/07  11:52:31  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wstandout.c,v 1.1 1991/09/07 11:52:31 sie Exp $";

#include "curses.h"


wstandout(WINDOW *WinPtr)
{
  if(!WinPtr)
    return ERR;
  
  WinPtr->_attrs |= A_STANDOUT;
}
