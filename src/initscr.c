/* -*-C-*-
 *
 *
 * Filename : initscr.c
 *
 * Author   : Simon J Raybould.    (sie@fulcrum.bt.co.uk).
 *
 * Date     : Friday 23rd August 1991.
 *
 * Desc     : Initialise curses.
 *
 *
 * THIS CODE IS NOT PUBLIC DOMAIN
 * ==============================
 * 
 * This code is copyright Simon J Raybould 1991, all rights are reserved.
 * All code, ideas, data structures and algorithms remain the property of the
 * author. Neither the whole nor sections of this code may be used as part
 * of other code without the authors consent. If you wish to use some of this
 * code then please email me at (sie@fulcrum.bt.co.uk).
 *
 * This source is not public domain, so you do not have any right to alter it
 * or sell it for personal gain. The source is provided purely for reference
 * purposes. You may re-compile the source with any compiler you choose.
 * You must not distribute altered copies without the authors consent. My
 * intention is that the source will help people isolate any bugs much more
 * effectivly.
 *
 * Disclaimer
 * ==========
 *
 * No implication is made as to this code being fit for any purpose at all.
 * I (the author) shall not be held responsible for any loss of data or damage 
 * to property that may result from its use or misuse.
 *
 *
 * Revision History
 * ================
 *
 * $Log:	initscr.c,v $
 * Revision 1.4  92/06/10  23:44:41  sie
 * Added serial support.
 * 
 * Revision 1.3  92/01/25  23:54:31  sie
 * Now uses fontheight and fontwidth.
 * Different algorithm for working out LINES and COLS.
 * 
 * Revision 1.2  91/12/30  10:31:03  sie
 * Removed LRLine and LRATTRS.
 * The speed increase caused by them was too insignificant.
 * 
 * Revision 1.1  91/09/07  11:43:35  sie
 * Initial revision
 * 
 *
 */

static char *rcsid = "$Header: SRC:lib/curses/src/RCS/initscr.c,v 1.4 92/06/10 23:44:41 sie Exp $";

#include "acurses.h"


static struct NewScreen NewScreen = {
  0, 0, 0, 0, 4, 0, 1, HIRES, CUSTOMSCREEN, NULL, "Curses screen", NULL, NULL
};

static struct NewWindow NewWindow = {
  0, 0, 0, 0, -1, -1, RAWKEY, ACTIVATE | BORDERLESS, NULL, NULL, NULL, NULL,
  NULL, 0,0,0,0, CUSTOMSCREEN
};

/*
 *  Make version number appear when right mouse button is pressed.
 */
static struct Menu _CursesMenu = {
  NULL, 0, 0, 0, 0, 0,
  "AMIGA CURSES by Simon J Raybould  V2.00 30.Jun.92",
  NULL, 0, 0, 0, 0
};

UWORD ColourTable[] = {
  0x000, 0xfff, 0xff0, 0x00f, 0xf0f, 0x0ff, 0xf00, 0x0f0
};

int
BreakHandler(void)
{
  endwin();			/* tidy up */
  fprintf(stderr, "Amiga Curses exiting after receiving interrupt signal\n");
  CleanExit(20);
  return 0;
}

initscr(void)
{
  char *Ptr, *getenv(const char *);
  int Tmp, BreakHandler();
  struct Screen WBScreen;
  
  /*
   *  It would be devestating if someone called initscr() twice
   *  so make subsequent calls fail.
   */
  if(CursesFlags & CFLAG_INITSCR)
    return ERR;
  
  CursesFlags |= CFLAG_INITSCR;
  
  CursesType = CUST_CURSES;
  if(Ptr = getenv("CURSESTYPE")) {
    if(!strcmp(Ptr, "ansi"))
      CursesType = ANSI_CURSES;
  }
  if(CursesType == CUST_CURSES) {
    if((IntuitionBase = (struct IntuitionBase *)
	OpenLibrary("intuition.library", 0)) == NULL) {
      fprintf(stderr, "Failed to open Intuition library");
      CleanExit(10);
    }
    /* Open graphics library */
    if((GfxBase = (struct GfxBase *)
	OpenLibrary("graphics.library", 0))==NULL) {
      fprintf(stderr, "Failed to open Graphics library");
      CleanExit(10);
    }
    /* Get Font height and Width */
    if(!GetScreenData((char *)&WBScreen, sizeof(struct Screen), WBENCHSCREEN,
		      NULL)) {
      printf("Can't get screen size\n");
      exit(10);
    }
    
    NewScreen.Height = NewWindow.Height = WBScreen.Height;
    NewScreen.Width = NewWindow.Width = WBScreen.Width;
    NewScreen.Depth = DEPTH;
    /* Set interlace if height >= 400 */
    if(NewScreen.Height>400)
      NewScreen.ViewModes |= LACE;
    
    /*
     * must have the console.device opened to use RawKeyConvert()
     */
    if(OpenDevice("console.device", -1L, (struct IORequest *)&ioreq, 0L))
      CleanExit(10);
    ConsoleDevice=(struct Library *)ioreq.io_Device;
    
    if((CursesScreen=(struct Screen *)OpenScreen(&NewScreen)) == NULL) {
      fprintf(stderr, "Failed to open Screen");
      CleanExit(10);
    }
    RPort = &(CursesScreen->RastPort);
    VPort = &(CursesScreen->ViewPort);
    /* Get font size */
    FontHeight = RPort->Font->tf_YSize;
    FontWidth = RPort->Font->tf_XSize;
    FontBase = RPort->Font->tf_Baseline;

    LINES = NewScreen.Height/FontHeight;
    COLS = NewScreen.Width/FontWidth;
  }
  
  /* if LINES and/or COLS set as environment variables then use them */
  if((Ptr = getenv("LINES"))) {
    Tmp = atoi(Ptr);
    if(Tmp>0 && Tmp<=MAXLINES)
      LINES = Tmp;
  }
  if((Ptr = getenv("COLS"))) {
    Tmp = atoi(Ptr);
    if(Tmp>0 && Tmp<=MAXCOLS)
      COLS = Tmp;
  }

  if(CursesType == CUST_CURSES) {
    LoadRGB4(VPort, ColourTable, (1<<DEPTH));
    SetDrMd(RPort, JAM2);
    SetAPen(RPort, 1);
    NewWindow.Screen = CursesScreen;  /* Must do this !! */
    if((CursesWindow=(struct Window *)OpenWindow(&NewWindow)) == NULL) {
      fprintf(stderr, "Failed to open Window\n");
      CleanExit(10);
    }
    SetMenuStrip(CursesWindow, &_CursesMenu);
  }
  
  /* Create stdscr and curscr */
  stdscr = newwin(LINES, COLS, 0, 0);
  curscr = newwin(LINES, COLS, 0, 0);  /* used for redraws */
#ifdef LATTICE
  if(onbreak(BreakHandler)) {
    fprintf(stderr, "Failed to set BREAK handler.\n");
    CleanExit(10);
  }
#else /* LATTICE */
  if ((int)signal(SIGINT, BreakHandler) == -1) {
    perror("Failed to set BREAK handler.");
    CleanExit(10);
  }
#endif /* else LATTICE */

  if(CursesType == ANSI_CURSES) {
    ifh = Input();
    if(CursesFlags & CFLAG_CBREAK)
      RawMode(ifh);
  }
  return OK;
}
