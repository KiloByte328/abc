#ifndef Terms
#define Terms
#include <stdio.h>
enum colors
{
    cl_black,
	cl_red,
	cl_green,
	cl_brown,
	cl_blue,
	cl_magenta,
	cl_cyan,
	cl_light_blue,
	cl_default
};

int mt_clrscr ();
int mt_goto (int x, int y);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolors(enum colors);
int mt_setbgcolors(enum colors);

#endif // !Terms