/*
 *
 *
 * Filename : Workbench2.0:src/curses/tgetstr.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Sat Feb 06 22:52:41 1993
 *
 * Desc     : tgetstr()
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
 * $Log: tgetstr.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tgetstr.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include <string.h>
#include "acurses.h"

char *
tgetstr(char *cn, char **ptr)
{
  int i;
  char *cptr, *tptr;
  
  if(strlen(cn) != CAP_LEN)
    return (char *)0;
  
#ifdef FUTURE
  if(_CursesType == CUST_CURSES) {
    tptr = *ptr;
    strcpy(tptr, cn);
    *ptr+=strlen(cn)+1;
    return tptr;
  }
#endif

  /* find the capability string */
  for(i=0; i< __no_caps; i++) {
    if(!strncmp(cn, __capary[i], CAP_LEN)) { /* if it's this one */
      cptr = __capary[i] + CAP_LEN;
      if(*cptr++ == '=') {
        while(*cptr == ' ' || *cptr == '\t') /* ignore leading WS */
          cptr++;
        tptr = *ptr;
        strcpy(tptr, cptr);
        *ptr+=strlen(cptr)+1;
        return tptr;
      }
    }
  }
  return (char *)0;
}
