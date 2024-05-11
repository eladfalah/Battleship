%macro _insert_ship 2;

	mov rax, %1; get position in the ships array
	mov rcx, %2; get iput ship addres
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
