/*
 *
 *
 * Filename : wattron.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Turn an attribute on.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: wattron.c,v $
 * Revision 1.4  1993/05/17  23:33:10  sie
 * Underscores added to names.
 * Changes for version 2.10
 *
 * Revision 1.3  1992/06/10  23:44:56  sie
 * Added serial support.
 *
 * Revision 1.2  91/12/28  22:45:29  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.1  91/09/07  11:49:15  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/wattron.c,v 1.4 1993/05/17 23:33:10 sie Exp $";

#include "acurses.h"



wattron(WINDOW *WinPtr, UBYTE attr)
{
  if(!WinPtr)
    return ERR;
  
  /* If attributes contain a colour change then mask off old colour */
  if(attr & A_CLRPART)
    WinPtr->_attrs &= ~A_CLRPART;
  
  WinPtr->_attrs |= attr;
  return OK;
}
