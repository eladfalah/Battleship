%include "helpers.inc"
extern ui  ;
section .data;
section .bss;
ships resb 3;
section .text;
	global _start;
	_start:
		call ui;
		exit;
