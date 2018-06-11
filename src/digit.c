#include "calc.h"

void digit(WINDOW *win) {

	int x = 5;
	int y = 6;
	const int data_height = 4;
	const int data_width = 31;

	WINDOW *data = newwin(data_height, data_width, 1, 1);
	box(data, 0, 0);

	mvprintw(y, x, "[C]");
	x = x + 5;
	mvprintw(y, x, "[7]");
	x = x + 5;
	mvprintw(y, x, "[8]");
	x = x + 5;
	mvprintw(y, x, "[9]");
	x = x + 5;
	mvprintw(y, x, "[/]");
	x = 5;
	y = y + 2;
	mvprintw(y, x, "[(]");
	x = x + 5;
	mvprintw(y, x, "[4]");
	x = x + 5;
	mvprintw(y, x, "[5]");
	x = x + 5;
	mvprintw(y, x, "[6]");
	x = x + 5;
	mvprintw(y, x, "[*]");
	x = 5;
	y = y + 2;
	mvprintw(y, x, "[)]");
	x = x + 5;
	mvprintw(y, x, "[1]");
	x = x + 5;
	mvprintw(y, x, "[2]");
	x = x + 5;
	mvprintw(y, x, "[3]");
	x = x + 5;
	mvprintw(y, x, "[-]");
	x = 5;
	y = y + 2;
	mvprintw(y, x, "[^]");
	x = x + 5;
	mvprintw(y, x, "[0]");
	x = x + 5;
	mvprintw(y, x, "[.]");
	x = x + 5;
	mvprintw(y, x, "[=]");
	x = x + 5;
	mvprintw(y, x, "[+]");
	x = x + 5;
	
	wrefresh(win);
	wrefresh(data);
}
