/*
 * Copyright (c) 1995 Danny Gasparovski.
 * 
 * Please read the file COPYRIGHT for the 
 * terms and conditions of the copyright.
 */

/*
 * Set/reset terminal attributes.
 * 
 * If the fd is not a tty, then do nothing.  This allows people
 * to use slirp over rsh or whatever.  A tty/pty is not necessary.
 */

#include <slirp.h>

void
term_raw(ttyp)
	struct ttys *ttyp;
{
	struct termios tempio;
	
	if (!isatty(ttyp->fd))
	   return;
	
	tcgetattr(ttyp->fd, &tempio);
	ttyp->oldterm = tempio;
	
	tempio.c_iflag = 0;
	tempio.c_oflag = 0;
	tempio.c_lflag = 0;
	
	/*
	 * Ok, I'm making this the default now *sigh*
	 */
#ifndef USE_LOWCPU
	tempio.c_cc[VMIN] = 1;
	tempio.c_cc[VTIME] = 0;
#else
	tempio.c_cc[VMIN] = 255;
	tempio.c_cc[VTIME] = 2;
#endif
	
#ifdef DO_CFSETSPEED
	cfsetospeed(&tempio, baud);
	cfsetispeed(&tempio, baud);
#endif
	
	tcsetattr(ttyp->fd, TCSANOW, &tempio);
}


void 
term_restore(ttyp)
	struct ttys *ttyp;
{
	if (!isatty(ttyp->fd))
	    return;
	
	tcsetattr(ttyp->fd, TCSANOW, &ttyp->oldterm);
}

