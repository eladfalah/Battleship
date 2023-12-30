%macro exit 0
	mov rax, 60;
	mov rbx, 0;
	syscall
%endmacro
