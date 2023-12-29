#include <stdio.h>
#include <stdlib.h>
#include "setting.h"
void moveCursor(int x, int y) {
    printf("\e[%d;%dH", y, x);
}
void printLineSection(int i, int j, char a, char b, char c){

			moveCursor(j, i);
			printf("%c%c%c",a, b, c);
			
}
void buildgrid(){
	for(int i=0;i<28;i+=2){
		for(int j=0;j<150;j+=3){
		printLineSection(i, j,'+','-','-');
		printLineSection(i+1, j, '|', ' ', ' ');
		}
		
		
		
	}
fflush(stdout);
}
