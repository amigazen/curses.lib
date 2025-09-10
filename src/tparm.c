/*
 *
 * Filename : SRC:lib/curses/src/tparm.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Mon Aug 16 21:40:58 1993
 *
 * Desc     : tparm() call, obvious really.
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
 * $Log: tparm.c,v $
 * Revision 1.1  1994/02/21  22:18:41  sie
 * Initial revision
 *
 *
 *
 */

#ifndef TARGET
#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tparm.c,v 1.1 1994/02/21 22:18:41 sie Exp $";
#endif /* lint */
#endif /* TARGET */





char *
tparm(char *str, ...)
{
  static char buf[80];
  char *ptr = str, *bptr = buf;
  
  while(*ptr) {
    if(*ptr == '%') {
      if(!*++ptr)
        break;
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
