# 
#
# Filename     : Makefile
#
# Author       : Simon J Raybould.
#
# Date         : Friday 23rd August 1991.
#
# Desc         : Makefile for Amiga curses library.
#
#
# Copyright (c) 1991-1993 Simon J Raybould
#
# SPDX-License-Identifier: BSD-2-Clause
#
#
# Revision History
# ================
#
# $Log: Makefile,v $
# Revision 1.12  2025/09/05  21:18:08  amigazen
# Revised to build with SAS/C 6.58 and NDK 3.2
#
# $Log: Makefile,v $
# Revision 1.11  1994/02/21  22:18:08  sie
# Added setupterm.c
#
# Revision 1.10  1993/05/17  23:42:07  sie
# tidying up.
#
# Revision 1.9  1993/05/17  23:33:10  sie
# Underscores added to names.
# Changes for version 2.10
#
# Revision 1.8  1992/12/25  22:22:09  sie
# Changes for the GNU C port.
#
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

VER= V2.10
SRCS=	wclrtobot.c flushinp.c wgetstr.c subwin.c mvprintw.c wscanw.c \
	scanw.c mvwscanw.c mvscanw.c printw.c newwin.c _creatwin.c \
	touchwin.c delwin.c mvwin.c scroll.c wsetscrreg.c _scroll.c \
	scrollok.c wnoutrefresh.c doupdate.c echo.c noecho.c beep.c \
	wrefresh.c initscr.c wgetch.c wstandout.c keypad.c flash.c \
	initcolour.c _data.c startcolour.c hascolours.c waddstr.c \
	waddch.c winsch.c wdelch.c wclear.c werase.c clearok.c wclrtoeol.c \
	wstandend.c wattrset.c wattron.c wattroff.c cbreak.c nocbreak.c \
	idlok.c winsertln.c wdeleteln.c nodelay.c resetty.c savetty.c \
	resetterm.c fixterm.c saveterm.c baudrate.c nl.c nonl.c box.c \
	mvwprintw.c _togcur.c wmove.c _zapcur.c _drawcur.c _exit.c endwin.c \
	mvcur.c wprintw.c leaveok.c winch.c _doecho.c _cleanup.c \
	_ansi.c gettmode.c longname.c overlay.c overwrite.c \
	_mergewin.c setterm.c unctrl.c tgetent.c tgetstr.c tputs.c \
	tgoto.c tgetnum.c tgetflag.c setupterm.c


CC= sc
CP= copy
RM= delete
TAGS= etags
OBJS= $(SRCS:.c=.o)
#DEBUG  = DEFINE DEBUG debug=ff
#TSTOPTS = COVERAGE
CFLAGS = DEFINE NO_SCAN_PROTOS $(DEBUG) $(TSTOPTS)
LIB    = curses.lib
LIBDIR = /SDK/lib/

.c.o:
	$(CC) $(CFLAGS) $<

all: $(LIB)


$(LIB): $(OBJS)
	-$(RM) $(LIB)
	join #?.o AS $(LIB)

install: $(LIB)
	-$(CP) $(LIB) $(LIBDIR) CLONE
	$(CP) curses.h INCLUDE: CLONE

$(OBJS): acurses.h curses.h

TAGS: $(SRCS)
	$(TAGS)	$(SRCS)

protos: $(SRCS)
	$(CC) GPROTO $(SRCS)
	join #?_protos.h as protos.h
	-$(RM) #?_protos.h #?_protos.h.info

clean:
	-$(RM) #?~
	-$(RM) #?.info
	-$(RM) $(OBJS)
	-$(RM) TAGS
	-$(RM) $(LIB)
