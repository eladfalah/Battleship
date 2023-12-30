%include "helpers.inc"
extern ui  ;
section .data;
section .bss;
section .text;
	global _start;
	_start:
		call ui;
		exit;
