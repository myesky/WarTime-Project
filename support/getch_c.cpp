#include <stdio.h>

#include <string.h>

#include <stdlib.h>
#include "termios.h"

#include <unistd.h>
int getch_c (void){

	int ch;

	struct termios oldt, newt;

	tcgetattr(STDIN_FILENO, &oldt);

	newt = oldt;

	newt.c_lflag &= ~(ECHO|ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

	return ch;

}
