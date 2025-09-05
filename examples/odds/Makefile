CC= lc
CFLAGS= -cw
MAKE= lmk

all: knight rain worms fm


knight: knight.c
	$(CC) $(CFLAGS) -L+llib:curses.lib+lib:lcm.lib $@

rain: rain.c
	$(CC) $(CFLAGS) -L+llib:curses.lib+lib:lcm.lib $@

worms: worms.c
	$(CC) $(CFLAGS) -L+llib:curses.lib+lib:lcm.lib $@

fm: fm.c
	$(CC) $(CFLAGS) -L+llib:curses.lib $@

clean:
	-delete \#?.lnk \#?.o \#?.info

clobber:
	$(MAKE) clean
	-delete knight
	-delete rain
	-delete worms
	-delete fm
