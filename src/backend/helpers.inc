;.global ROWS;
;.global COLUMNS;
section .data
ROWS dd 0xA;
COLUMNS dd 0x14;


%macro exit 0
	mov rax, 60;
	mov rbx, 0;
	syscall
%endmacro
	%macro _print 1;
		mov rax, %1;
		push rax;
		mov rbx, 0;
		%%pLoop:
			inc rax;
			inc rbx;
			mov cl, [rax];
			cmp cl, 0;
			jne %%pLoop;
		mov rax, 1;
		mov rdi, 1;
		pop rsi;
		mov rdx, rbx;
		syscall;
	%endmacro;
