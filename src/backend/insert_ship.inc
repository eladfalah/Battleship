extern ROWS;
extern COLUMNS;
%macro _insert_ship 2;

	mov rax, %1; get position in the ships array
	mov rcx, %2; get iput ship addres
	mov r8, rcx; copy input ship to r8 
	movzx r9 byte [r8]; put x pos in r9
	shr r8, 8; shift right for y pos
	movzx r10 byte [r8];put y in r10 
	cmp r9b, ROWS; check that x is in range
	jg insertingError; if ot of range go to error
	cmp r10b, COLUMNS; check if y is in range
	jg insertingError; if isn go to error
	shr r8, 8; shift right for the rest of te data
	mov r12, 3; min size of ship on the board
	movzx r11 byte [r8]; mov the rest of data to r11
	test r11b, 0b01000000; check if need to add 1
	jz add_two; 
	add r12, 1; add 1
	test r11b, 0b10000000; check if need to add 2
	jz %%direction;
	add r12, 2; add two
	%%direction:
	test r11b, 0b00100000;
	jnz horizontal;
	vertical:
	mov r13, ROWS;
	jmp isInFrame;
	horizontal:
	mov r13, COLUMNS;
	isInFrame:
	cmp r12, r13;
	jg insertingError;

	mov rbx, 3; 3 bytes > size of ship
	mul rbx; pos in array * ship size
	mov rdx, ships; get "ships" addres
	add rdx, rax; point to the new ship start point on ships
	mov rbx, 3; loop counter
	%%_inserting_loop:
	dec rbx; count down
	movzx rax, byte [rcx]; get the next byte of info from input ship
	mov [rdx], al; move the infi into the ships array
	inc rdx;next byte in ships array
	inc rcx;next byte of the input ship
	cmp rbx, 0;check if counter on 0
	jne %%_inserting_loop;if counter is not on 0 return to the begening of the loop
%endmacro;
