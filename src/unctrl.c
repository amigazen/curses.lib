/*
 *
 *
 * Filename : SRC:lib/curses/src/unctrl.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Wed Jan 20 23:24:03 1993
 *
 * Desc     : converts control caracters to printable sequences of the form
 *            "^A" for control-A
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
 * $Log: unctrl.c,v $
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/unctrl.c,v 1.1 1993/05/17 23:33:10 sie Exp $";
#endif /* lint */


char *
unctrl(char ch)
{
  static char buf[3];           /* longest string is 2 chars + terminator */

  if(ch < 32) {
    buf[0] = '^';
    buf[1] = ch + '@';          /* control-@ is 0 in ASCII */
    buf[2] = '\0';
  } else {
    buf[0] = ch;
    buf[1] = '\0';
  }
  return buf;
}
