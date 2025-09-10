/*
 *
 *
 * Filename : Workbench2.0:src/curses/tgoto.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Wed Feb 24 21:48:37 1993
 *
 * Desc     : goto a specified point on the screen.
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
 * $Log: tgoto.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tgoto.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */

#include <stdio.h>

static void swap(int *a, int *b) { int t; t = *a; *a = *b; *b = t; }

char *
tgoto(char *cm, int col, int line)
{
  static char buf[80];
  char *ptr = cm, *bptr = buf;
  
  while(*ptr) {
    if(*ptr == '%') {
      if(!*++ptr) break;
      switch(*ptr) {
      case 'd':                 /* decimal value */
        bptr += sprintf(bptr, "%d", line);
        swap(&line, &col);
        break;
      case '2':                 /* decimal value */
        bptr += sprintf(bptr, "%2d", line);
        swap(&line, &col);
        break;
      case '3':                 /* decimal value */
        bptr += sprintf(bptr, "%3d", line);
        swap(&line, &col);
        break;
      case '.':                 /* character value */
        bptr += sprintf(bptr, "%c", line);
        swap(&line, &col);
        break;
      case 'r':                 /* reverse line and col */
        swap(&line, &col);
        break;
      case 'i':                 /* in line and col */
        line++;
        col++;
        break;
      case '%':
        *bptr++ = '%';
        break;
      }
    } else
      *bptr++ = *ptr;
    ptr++;
  } /* end of while(*ptr) */
  return buf;
}

