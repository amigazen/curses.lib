/*
 *
 *
 * Filename : Workbench2.0:src/curses/tgetnum.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Thu Feb 25 21:28:42 1993
 *
 * Desc     : Gets a numeric value of capability id.
 *
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: tgetnum.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tgetnum.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */


#include "acurses.h"


tgetnum(char *id)
{
  int i;
  
  if(strlen(id) != CAP_LEN)
    return -1;
  
#ifdef FUTURE                   /* These are the starts of future enhancements */
                                /* or is it a Leonard Cohen album ? */
  if(_CursesType == CUST_CURSES) {
    switch(*((short *)id)) {
    case 0x6c69:                /* li */
      return LINES;
      break;
    case 0x636f:                /* co */
      return COLS;
      break;
    }
  } else {
#endif
  /* find the capability string */
  for(i=0; i< __no_caps; i++) {
    if(!strncmp(id, __capary[i], CAP_LEN)) { /* if it's this one */
      if(__capary[i][2] != '#') /* if it's not a number capability */
        return -1;
      return atoi(&__capary[i][3]);
    }
  }
#ifdef FUTURE
  }
#endif
  return -1;                    /* not found */
}
