/*
 *
 *
 * Filename : _creatwin.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Creats a new window, which may or may not be a sub window.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 *
 * Revision History
 * ================
 *
 * $Log: _creatwin.c,v $
 * Revision 1.7  1993/05/17  23:31:21  sie
 * Underscores added to names.
 *
 * Revision 1.6  1992/06/10  23:45:07  sie
 * Added serial support.
 *
 * Revision 1.5  91/12/30  10:30:22  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 * 
 * Revision 1.4  91/12/28  22:46:13  sie
 * changed attrs to UBYTE from short + some tidying up.
 * 
 * Revision 1.3  91/12/28  14:01:54  sie
 * Removed WinStat.
 * Renamed LineElement as lnel.
 * 
 * Revision 1.2  91/12/26  14:40:31  sie
 * removed use of Next and Prev in WinStat as linked list is no longer
 * relevant.
 * 
 * Revision 1.1  91/09/07  11:52:46  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_creatwin.c,v 1.7 1993/05/17 23:31:21 sie Exp $";

#include <stdlib.h>
#include "acurses.h"


/* Orig is NULL and StartCol/Line are not used for newwin() calls */
WINDOW *_CreatWindow(int NLines, int NCols, int StartLine, int StartCol, WINDOW *Orig)
{
  int Line;
  WINDOW *NewWinPtr;
  
  /* If either are zero then make them max */
  if(!NLines)
    NLines = LINES - StartLine;
  if(!NCols)
    NCols = COLS - StartCol;
  
  if(NLines>LINES || NCols>COLS || StartLine>LINES || StartCol>COLS)
    return NULL;
  
  if(StartLine < 0)
    StartLine = 0;
  if(StartCol < 0)
    StartCol = 0;
  
  /* Create a new WINDOW structure */
  if(!(NewWinPtr=(WINDOW *)malloc(sizeof(WINDOW)))) {
    fprintf(stderr, "CreatWindow() - Not enough memory\n");
    return NULL;
  }
  NewWinPtr->ParentWin = Orig;
  NewWinPtr->ScrollTop = 0;
  NewWinPtr->ScrollBot = NLines - 1;
  NewWinPtr->NLines = NLines;
  /* Allocate space for LnArry[] */
  if(!(NewWinPtr->LnArry = (struct lnel *)malloc(sizeof(struct lnel)*NLines))) {
    fprintf(stderr, "CreatWindow() - Not enough memory\n");
    return NULL;
  }
  /* Allocate space for Line and ATTRS */
  for(Line = 0; Line < NLines; Line++) {
    if(Orig) {  /* If this is a subwindow */
      /* Set up pointers into parent window */
      NewWinPtr->LnArry[Line].Line =
	&Orig->LnArry[Line+StartLine].Line[StartCol];
      NewWinPtr->LnArry[Line].ATTRS =
	&Orig->LnArry[Line+StartLine].ATTRS[StartCol];
    } else {  /* New window, allocate space for lines */
      /* malloc lines and ATTRS */
      if((NewWinPtr->LnArry[Line].Line = malloc(NCols)) == NULL) {
	fprintf(stderr, "CreatWindow() - Not enough memory\n");
	return (WINDOW *)NULL;
      }
      if((NewWinPtr->LnArry[Line].ATTRS = (UBYTE *)malloc(NCols)) == NULL) {
	fprintf(stderr, "CreatWindow() - Not enough memory\n");
	return (WINDOW *)NULL;
      }
    }
    NewWinPtr->LnArry[Line].Touched = FALSE;
    NewWinPtr->LnArry[Line].StartCol = NCols;
    NewWinPtr->LnArry[Line].EndCol = 0;
  }
  /* Initialise rest of the window structure */
  NewWinPtr->_cury = 0;
  NewWinPtr->_curx = 0;
  NewWinPtr->_maxy = NLines - 1;
  NewWinPtr->_maxx = NCols - 1;
  NewWinPtr->_begy = StartLine;
  NewWinPtr->_begx = StartCol;
  NewWinPtr->_flags = 0;
  NewWinPtr->_attrs = A_NORMAL | COLOR_WHITE;
  NewWinPtr->_clear = FALSE;
  NewWinPtr->_scroll = FALSE;
  NewWinPtr->_nodelay = 0;
  
  return NewWinPtr;
}
