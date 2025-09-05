/*
 *
 *
 * Filename : Workbench2.0:src/curses/tgetflag.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Thu Feb 25 22:14:56 1993
 *
 * Desc     : returns 1 if flag exists, else returns 0.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Revision History
 * ================
 *
 * $Log: tgetflag.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tgetflag.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */


#include "acurses.h"


tgetflag(char *id)
{
  int i;
  
  if(strlen(id) != CAP_LEN)
    return -1;
  
  /* find the capability string */
  for(i=0; i< __no_caps; i++)
    if(!strncmp(id, __capary[i], CAP_LEN)) /* if it's this one */
      return 1;                 /* found it */

  return 0;                    /* not found */
}
