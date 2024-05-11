#include <asm-generic/errno-base.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include "buildgrid.h"
struct winsize wsize;
bool isRunning;
bool isUIchanged;
extern uint ROWS;
extern uint COLUMNS;
int key;
int ui() {
    isRunning = true;
    initscr();
    noecho();
    curs_set(0); // hide cursor
    isUIchanged = true;
    keypad(stdscr, TRUE);
    while (isRunning) {
        if (isUIchanged) {
            clear();
            refresh();
            buildgrid(COLUMNS*3, ROWS*2);
            isUIchanged = false;
        }

        key = getch();
        switch (key) {
            case KEY_DOWN:
                break;

            case 'q':
            case 'Q':
                isRunning = false;
                break;
        }
    }
	clear();
	erase();
	refresh(); // Add a refresh call to ensure changes take effect
	endwin();
	return 0;
}

