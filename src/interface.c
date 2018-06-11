#include "calc.h"

void interface(char *str) {
    
	const int width = 33;
	const int height = 15;
	char empty[25];

	double result = 0.0;
	size_t cnt = 0;

	for (cnt = 0; cnt < 25; cnt++) {
		empty[cnt] = ' ';
	}
	empty[24] = '\0';
	cnt = 0;

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	initscr();
	curs_set(0);
	refresh();
	WINDOW *win = newwin(height, width, 0, 0);
	int key = 0;
	box(win, 0, 0);
	wrefresh(win);
	noecho();
	keypad(stdscr, TRUE);

	int x = 4;
	int y = 6; 

	size_t i = 0;
	wrefresh(win);
	while(1)
	{	  
		box(win, 0, 0);
		mvprintw(y, x, ">");
		mvprintw(y, x+4, "<");
		digit(win);
		int ch = getch();
		if (ch == KEY_DOWN){
			y = y + 2;
		}
		if (ch == KEY_UP) {
			y = y - 2;
		}
		if (ch == KEY_LEFT) {
			x = x - 5;
		}
		if (ch == KEY_RIGHT) {
			x = x + 5;
		}
		if (ch == '\n') {
			key = check(str, x, y, &i);
			if (key != 0) {
				break;
			}
		}
		if (y > 12) {
		   y = 12;
		}
		if (y < 6) {
			y = 6;
		}
		if (x < 4) {
			x = 4;
		}
		if (x > 24) {
			x = 24;
		}
		
		clear();
		refresh();

		//printw(" x%d y%d \nr%d", x ,y);
		mvaddstr(3, (width)/6, str);
		wrefresh(win);
	}
	mvaddstr(3, width/6, empty);
	result = summ(str, &cnt);
	sprintf(str, "%.3lf", result);
	mvaddstr(3, (width)/6, str);
	getch();
	int t;
			for (t = 0; t < 20; t++) {
				str[t] = ' ';
			}
			i = 0;
	delwin(win);
	endwin();
}



