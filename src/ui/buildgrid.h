#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void buildgrid(){
	int i, j;
	for(i=0;i<=28;i+=2){
		for(j=0;j<=150;j+=3){
		printLineSection(i, j, (j < 150) ? "+--E" : "+E");
		if(i<28)printLineSection(i+1, j, (j < 150) ? "|  E" : "|E");
		}	
	}
fflush(stdout);
}
