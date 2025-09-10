/*
 *
 *
 * Filename : _cleanup.c
 *
 * Author   : Simon J Raybould.
 *
 * Date     : Saturday 24th August 1991.
 *
 * Desc     : Free resources.
 *
 * Copyright (c) 1991-1993 Simon J Raybould
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Revision History
 * ================
 *
 * $Log: _cleanup.c,v $
 * Revision 1.2  1993/05/17  23:29:20  sie
 * Underscores added to names.
 *
 * Revision 1.1  1991/09/07  11:52:37  sie
 * Initial revision
 *
 *
 */

static char *rcsid = "$Header: /SRC/lib/curses/src/RCS/_cleanup.c,v 1.2 1993/05/17 23:29:20 sie Exp $";

#include "acurses.h"


void
_CleanUp(void)
{
  if(_CursesWindow) {
    CloseWindow(_CursesWindow);
    _CursesWindow = NULL;
  }
  if(_CursesScreen) {
    CloseScreen(_CursesScreen);
    _CursesScreen = NULL;
  }
  if(GfxBase) {
    CloseLibrary((struct Library *)GfxBase);
    GfxBase = NULL;
  }
  if(IntuitionBase) {
    CloseLibrary((struct Library *)IntuitionBase);
    IntuitionBase = NULL;
  }
}
