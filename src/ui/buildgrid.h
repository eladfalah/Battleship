#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
void moveCursor(int x, int y) {
    printf("\e[%d;%dH", y, x);
}
void printLineSection(int x, int y, const char *chars){
			int i = 0;
			char printedChar;
			moveCursor( y, x);
			printedChar=chars[i];
			while (printedChar!='E'){
				printf("%c",printedChar);
				i++;
				printedChar=chars[i];
			}
}
void buildgrid(uint columns, uint rows){
	uint i, j;
	for(i=0;i<=rows;i+=2){
		for(j=0;j<=columns;j+=3){
		printLineSection(i, j, (j < columns) ? "+--E" : "+E");
		if(i<rows)printLineSection(i+1, j, (j < columns) ? "|  E" : "|E");
		}	
	}
fflush(stdout);
}
