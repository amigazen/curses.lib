/* 
 * Copyright (c) 2025 amigazen project
 *
 * Local term.h header for termcap/terminfo functions
 *
 * This header provides function prototypes for the termcap functions
 * implemented in this curses library. This is a local implementation
 * to avoid dependency on external term.h files.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef _TERM_H
#define _TERM_H

/* Termcap function prototypes */
int tgetent(char *buffer, char *terminal);
char *tgetstr(char *cn, char **ptr);
int tgetflag(char *id);
int tgetnum(char *id);
char *tgoto(char *cm, int col, int line);

/* Terminfo function prototypes */
/* int setupterm(char *term, int fildes, int *errret); */

/* Internal setupterm function (void version used in this project) */
void setupterm(void);

#endif /* _TERM_H */
