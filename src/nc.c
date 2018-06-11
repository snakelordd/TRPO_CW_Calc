#include "calc.h"



/*int main(){
    char str[SIZE] = " ";
    interface(str);
    return 0;

}*/
void interface(char *str)
{
	const int width = 33;
    const int height = 15;
    
    

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }
    initscr();
    curs_set(0);
    refresh();
    //int offsetx = (COLS - width) / 2;
    //int offsety = (LINES - height) / 2;

    WINDOW *win = newwin(height, width, 0, 0);
    
    //char text[] = "Enter expression";
    int result = 0;

    //mvaddstr(3, (width-strlen(text))/2, text);
    
    box(win, 0, 0);

    wrefresh(win);
    //wrefresh(data);

    noecho();
    keypad(stdscr, TRUE);

    int x = 4;
    int y = 6;
    
    int i = 0;
    /*
    for (i =0; i < 5; i++) {
        char a = 'a';
        str[i] = a;
        a++;
    }*/
    mvaddstr(3, (width-strlen(str))/2, str);
    
    
    
    
    while(1)
    {
       
    	box(win, 0, 0);
    	
        mvprintw(y, x, ">");
        mvprintw(y, x+4, "<");

        digit(win);
        //box(data, 0, 0);
        

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
			result = check(str, x, y, &i);	
			if (result != 0) {
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
        if ( x == 24 && y == 12) {
            x = 19;
            y = 12;
        }

        clear();
        refresh();

        printw(" x%d y%d \nr%d", x ,y, result);
        mvaddstr(3, (width-strlen(str))/2, str);
        //wrefresh(data);
        //wrefresh(win);
        
         
    }
    
    //int i;
    //for (i = 0; i < result; i++) {
    //	printw("%c", str[i]);
    //}
    //mvaddstr(1, (width-strlen(str))/2, str);

    delwin(win);
    //delwin(data);

    endwin();
}

int check(char *str, int x, int y, int *i) {
	if ( x == 4) {
		if (y == 6) {
			str[*i] = '9';
			++*i;
		}
		if (y == 8) {
			str[*i] = '6';
			++*i;
		}
		if (y == 10) {
			str[*i] = '3';
			++*i;
		}
		if (y == 12) {
			str[*i] = '0';
			++*i;
		}
	}
	if (x == 9) {
		if ( y == 6){
			str[*i] = '8';
			++*i;
		}
		if (y == 8) {
			str[*i] = '5';
			++*i;
		}
		if (y ==10) {
			str[*i] = '2';
			++*i;
		}
		if (y == 12) {
			str[*i] = '.';
			++*i;
		}
	}	
	if (x == 14){ 
		if(y == 6) {
			str[*i] = '7';
			++*i;
		}
		if (y == 8) {
			str[*i] = '4';
			++*i;
		}
		if (y == 10) {
			str[*i] = '1';
			++*i;
		}
		if ( y == 12) {
			str[*i] = '\0';
			return *i;
			++*i;
		}
	}
	if (x == 19)  {
		if(y == 6) {
			str[*i] = '/';
			++*i;
		}
		if (y == 8){
			str[*i] = '*';
			++*i;
		}
		if (y == 10) {
			str[*i] = '-';
			++*i;
		}
		if (y == 12) {
			str[*i] = '+';
			++*i;
		}
	}
    if ( x == 24) {
        if ( y == 6) {
            str[*i] = '(';
            ++*i;
        }
        if ( y == 8) {
            str[*i] = ')';
            ++*i;
        }
        if ( y == 10) {
            str[*i] = '^';
            ++*i;
        }
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

    
    mvprintw(y, x, "[9]");
    x = x + 5;
    mvprintw(y, x, "[8]");
    x = x + 5;
    mvprintw(y, x, "[7]");
    x = x + 5;
    mvprintw(y, x, "[/]");
    x = x + 5;
    mvprintw(y, x, "[(]");
    x = 5;
    y = y + 2;
    mvprintw(y, x, "[6]");
    x = x + 5;
    mvprintw(y, x, "[5]");
    x = x + 5;
    mvprintw(y, x, "[4]");
    x = x + 5;
    mvprintw(y, x, "[*]");
    x = x + 5;
    mvprintw(y, x, "[)]");
    x = 5;
    y = y + 2;
    mvprintw(y, x, "[3]");
    x = x + 5;
    mvprintw(y, x, "[2]");
    x = x + 5;
    mvprintw(y, x, "[1]");
    x = x + 5;
    mvprintw(y, x, "[-]");
    x = x + 5;
    mvprintw(y, x, "[^]");
    x = 5;
    y = y + 2;
    mvprintw(y, x, "[0]");
    x = x + 5;
    mvprintw(y, x, "[.]");
    x = x + 5;
    mvprintw(y, x, "[=]");
    x = x + 5;
    mvprintw(y, x, "[+]");
    wrefresh(win);  
    wrefresh(data);  
}


/*
int main()
{
    

    

    initscr();
    curs_set(0);
    refresh();

    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;

    WINDOW *win = newwin(height, width, offsety, offsetx);

    char hello[] = "Hello, world!";

    mvaddstr(LINES/2, (COLS-strlen(hello))/2, hello);
    box(win, 0, 0);

    wrefresh(win);
    getch();

    delwin(win);
    endwin();
}
*/