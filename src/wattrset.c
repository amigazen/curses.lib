/*
 *
 *
 * Filename : wattrset.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Set attributes.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wattrset.c,v $
 * Revision 1.3  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.2  1991/12/28  22:45:32  sie
 * changed attrs to UBYTE from short + some tidying up.
 *
 * Revision 1.1  91/09/07  11:49:22  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wattrset.c,v 1.3 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"


wattrset(WINDOW *WinPtr, UBYTE attr)
{
  if(!WinPtr)
    return ERR;
  
  /*
   *  Older code may inadvertently reset the attributes and set the
   *  forground colour to 0, in this case, set it to white.
   */
  if(!(attr & A_CLRPART))
    attr |= COLOR_WHITE;
  
  WinPtr->_attrs = attr;
  return OK;
}
