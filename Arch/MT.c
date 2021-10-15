#include "MT.h"

int mt_clrscr()
{
    printf ("\E[H\E[2J");
    return 0;
}

int mt_getscreensize(int *rows, int *cols)
{
    	struct winsize w;

	if (!ioctl(STDOUT_FILENO, TIOCGWINSZ, &w))
	{
		*rows = w.ws_row;
		*cols = w.ws_col;
		return 0;
	}
	else
		return 1;
}

int mt_goto(int x, int y)
{
    printf("\E[%d;%dH", y, x);
}

int mt_setbgcolors(enum colors bg_color)
{
    printf("\E[3%dm", bg_color);
}

int mt_setfgcolors(enum colors fg_color)
{
    printf("\E[4%dm", fg_color);
}