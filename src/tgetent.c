/*
 *
 *
 * Filename : Workbench2.0:src/curses/tgetent.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.co.uk).
 *
 * Date     : Sat Feb 06 20:03:26 1993
 *
 * Desc     : Get a terminal entry from the termcap file.
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
 * $Log: tgetent.c,v $
 * Revision 1.2  1994/02/21  22:19:54  sie
 * Added some conditional debug code.
 *
 * Revision 1.1  1993/05/17  23:33:10  sie
 * Initial revision
 *
 *
 */

#ifndef lint
static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/tgetent.c,v 1.2 1994/02/21 22:19:54 sie Exp $";
#endif /* lint */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "acurses.h"

static unsigned char
__CapEmpty(char *str)
{
  while(*str) {
    switch(*str++) {
    case ' ':
    case '\t':
      break;
    default:
      return FALSE;             /* This char isn't whitespace */
    }
  }
  return TRUE;                  /* Yep, It's all whitespace */
}

tgetent(char *buffer, char *terminal)
{
  char found = FALSE;
  char *termcap_file, *ptr;
  char line[LINE_LEN];
  int i, len, tnamelen;
  FILE *fp;
  
  __area = buffer;              /* store a pointer to the users buffer */
  
  if(!(termcap_file = getenv("TERMCAP")))
    termcap_file = DFLT_TERMCAP;
  
  if(!(fp = fopen(termcap_file, "r")))
    return -1;
  
  while(fgets(line, LINE_LEN, fp)) {
    if(line[0] == '#') continue; /* skip comments */
    len = strlen(line) - 1;     /* -1 to remove \n */
    line[len] = '\0';
    if(found) {
      if(line[len-1] == '\\') {
        len--;                  /* throw the \ away */
        memcpy(buffer, line, len);
        buffer += len;
      } else {
        memcpy(buffer, line, len);
        buffer += len;
        *buffer = '\0';        
        /* get pointers to the capabilities */
        __no_caps = 0;
        ptr = __area;
        while(__capary[__no_caps] = strtok(ptr, ":")) {
          if(__CapEmpty(__capary[__no_caps]))
             continue;
          /* convert the cap name to lower case */
          for(i=0; i<CAP_LEN; i++)
            __capary[__no_caps][i] = tolower(__capary[__no_caps][i]);
          __no_caps++;
          if(ptr)
            ptr = (char *)0;
        }          
        fclose(fp);
        return 1;               /* SUCCESS */
      }
    } else {                    /* Not found yet */
      if(line[len-1] == '\\') len--;
      memcpy(buffer, line, len);
      tnamelen = strlen(terminal);
      strtok(line, ":");
      ptr = strtok(line, "|");
      do {
        if(!strcmp(terminal, ptr)) {
          found = TRUE;
          buffer += len;
          break;                /* stop looking now */
        }
      } while(ptr = strtok((char *)0, "|"));
    }
  }                             /* end of while fgets */
  fclose(fp);
  *__area = '\0';
#ifdef DEBUG
  printf("%d capabilities found\n", __no_caps);
  for(i=0; i< __no_caps; i++)
    printf("cap %d = %s\n", i,  __capary[i]);
#endif /* DEBUG */
  
  return 0;                     /* not found */
}
