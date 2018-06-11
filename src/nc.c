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

int check(char *str, int x, int y, size_t *i) {
	if ( x == 4) {
		if (y == 6) {
			int t;
			for (t = 0; t < 20; t++) {
				str[t] = ' ';
			}
			*i = 0;
		}
		if (y == 8) {
			str[*i] = '(';
			++*i;
		}
		if (y == 10) {
			str[*i] = ')';
			++*i;
		}
		if (y == 12) {
			str[*i] = '^';
			++*i;
		}
	}
	if (x == 9) {
		if ( y == 6){
			str[*i] = '7';
			++*i;
		}
		if (y == 8) {
			str[*i] = '4';
			++*i;
		}
		if (y ==10) {
			str[*i] = '1';
			++*i;
		}
		if (y == 12) {
			str[*i] = '0';
			++*i;
		}
	}	
	if (x == 14){ 
		if(y == 6) {
			str[*i] = '8';
			++*i;
		}
		if (y == 8) {
			str[*i] = '5';
			++*i;
		}
		if (y == 10) {
			str[*i] = '2';
			++*i;
		}
		if ( y == 12) {
			str[*i] = '.';
			++*i;
		}
	}
	if (x == 19)  {
		if(y == 6) {
			str[*i] = '9';
			++*i;
		}
		if (y == 8){
			str[*i] = '6';
			++*i;
		}
		if (y == 10) {
			str[*i] = '3';
			++*i;
		}
		if (y == 12) {
			str[*i] = '\0';
			return *i;
		}
	}
	if ( x == 24) {
		if ( y == 6) {
			str[*i] = '/';
			++*i;
		}
		if ( y == 8) {
			str[*i] = '*';
			++*i;
		}
		if ( y == 10) {
			str[*i] = '-';
			++*i;
		}
		if ( y == 12) {
			str[*i] = '+';
			++*i;
		}
	}
	if ( *i > 20) {
		int t;
		for (t = 0; t < 20; t++) {
			//str[*i] = '\0';
			str[t] = ' ';
		}
		return 1;
	}
	
	return 0;

}

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
