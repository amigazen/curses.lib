/*
 *
 *
 * Filename : scanw.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : scanf()
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: scanw.c,v $
 * Revision 1.2  1992/12/25  23:38:27  sie
 * Fixed the bug with scanw().
 * There is no svscanf() function!
 *
 * Revision 1.1  91/09/07  11:46:35  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/scanw.c,v 1.2 1992/12/25 23:38:27 sie Exp $";

#include "curses.h"
#include <stdarg.h>


scanw(char *fmt,
      char *ptr1, char *ptr2, char *ptr3, char *ptr4, char *ptr5,
      char *ptr6, char *ptr7, char *ptr8, char *ptr9, char *ptr10)
{
  char buffer[BUFSIZ];
  
  getstr(buffer);
  return sscanf(buffer, fmt, ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7, ptr8, ptr9, ptr10);
}
