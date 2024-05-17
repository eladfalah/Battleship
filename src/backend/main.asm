%include "helpers.inc"
extern ui  ; 
section .data;
inp_ship db "a","b","c"; user input ship from the ui ()
section .bss;
ships resb 80;ships array
;inp_ship resb 3; x pos (8 bits), y pos (8 bits), size (2 bits), isHorizontal (1 bit), hits points (5 bites); 
section .text;
	global ROWS;
	global COLUMNS;
	global _start;
	_start:
		call ui;
		exit
