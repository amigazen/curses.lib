/*
 *
 *
 * Filename : Workbench2.0:src/curses/tputs.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Tue Feb 09 21:40:34 1993
 *
 * Desc     : tputs(3)
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
 * $Log: tputs.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tputs.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include "acurses.h"


int tputs(char *cp, int affcnt, int(*outc)(char))
{
  int delay = 0;
  
#ifdef FUTURE
  if(_CursesType == CUST_CURSES) {
    switch(*((short *)cp)) {
    case 0x636c:                /* cl */
      /* SetRast(); */
      break;
    }
  } else {
#endif
  while(isdigit(*cp)) {
    delay *= 10;
    delay += (*cp - '0');
    cp++;
  }
  if(*cp == '*') {              /* is it a delay per line affected ? */
    delay *= affcnt;
    cp++;
  }
  while(*cp) {
    switch(*cp) {
      case '\\':
      if(isdigit(*++cp))
        /* This must be a 3 digit octal number */
        outc((64*(*cp++ - '0') + 8*(*cp++ - '0') + (*cp - '0')) & 0x7f);
      else {
        switch(*cp) {           /* character after a \ */
        case 'E':
          outc(ESC);
          break;
        case 'n':
          outc(NL);
          break;
        case 'r':
          outc(CR);
          break;
        case 't':
          outc(TAB);
          break;
        case 'b':
          outc(BS);
          break;
        case 'f':
          outc(FF);
          break;
        case '^':
          outc('^');
          break;
        case '\\':
          outc('\\');
          break;
        }
      } /* end of else, so not an octal number */
      break;
      
    case '^':                   /* control character */
      {
        char c = *++cp;
        outc(toupper(c) - '@'); /* this line assumes ascii */
      }
      break;
      
    default:
      outc(*cp);
      break;
    }
    cp++;
  }
#ifdef FUTURE
}
#endif
  return 0;
}
