# -*-make-*-
##################################################################
#
# Desc   : Makefile for Amiga curses library.
#
# Author : Simon J Raybould.	(sie@fulcrum.bt.co.uk)
#
# Date   : Friday 23rd August 1991.
#
#
# Revision History
# ================
#
# $Log:	Makefile,v $
# Revision 1.7  92/06/10  23:44:42  sie
# Added serial support.
# 
# Revision 1.6  92/01/28  00:11:43  sie
# removed -q1e1w as these are now defaults.
# 
# Revision 1.5  92/01/28  00:10:40  sie
# compacts the header file.
# 
# Revision 1.4  92/01/25  23:53:48  sie
# clean now removed emacs temporary files as well.
# 
# Revision 1.3  91/12/28  22:49:15  sie
# made "clean" remove the library.
# 
# Revision 1.2  91/09/28  17:53:40  sie
# Put clone on both copy instructions.
# 
# Revision 1.1  91/09/07  11:55:48  sie
# Initial revision
# 
#
##################################################################


.c.o:
	$(CC) $(CFLAGS) $<
#	oml $(LIB) R $@
	oml $(LIB) R $>.o


VER= V2.00
CC= lc
OBJS=	wclrtobot.o flushinp.o wgetstr.o subwin.o mvprintw.o wscanw.o \
	scanw.o mvwscanw.o mvscanw.o printw.o newwin.o _creatwin.o \
	touchwin.o delwin.o mvwin.o scroll.o wsetscrreg.o _scroll.o \
	scrollok.o wnoutrefresh.o doupdate.o echo.o noecho.o beep.o \
	wrefresh.o initscr.o wgetch.o wstandout.o keypad.o flash.o \
	initcolour.o _data.o startcolour.o hascolours.o waddstr.o \
	waddch.o winsch.o wdelch.o wclear.o werase.o clearok.o wclrtoeol.o \
	wstandend.o wattrset.o wattron.o wattroff.o cbreak.o nocbreak.o \
	idlok.o winsertln.o wdeleteln.o nodelay.o resetty.o savetty.o \
	resetterm.o fixterm.o saveterm.o baudrate.o nl.o nonl.o box.o \
	mvwprintw.o _togcur.o wmove.o _zapcur.o _drawcur.o _exit.o endwin.o \
	mvcur.o wprintw.o leaveok.o winch.o _doecho.o _cleanup.o _ansi.o


#DEBUG= -d5
CFLAGS= $(DEBUG)

LIB= curses.lib
LIBDIR= LLIB:


$(LIB): $(OBJS) curses.h acurses.h
	copy $(LIB) $(LIBDIR) clone
	copy curses.h INCLUDE: CLONE

clean:
	-delete \#?.o
	-delete TAGS
	-delete $(LIB)
