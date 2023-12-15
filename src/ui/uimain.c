#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include "buildgrid.h"

int count=0;

struct winsize wsize;

bool isRuning;
int key;

int main(){
isRuning=true;
initscr();
noecho();
printf("\e[?25l");//hide cursor

keypad(stdscr, TRUE);
while (isRuning) {


clear();


refresh();
buildgrid();
key=getch();
switch (key) {
case KEY_DOWN:
        

case 'q':
case 'Q':
        isRuning=false;
                break;
}
}
endwin();
printf("\e[?25h");//how cursor

return 0;
}
