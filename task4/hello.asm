section .data
	nameAsk: db "What is your name?", 10
	nameAskLen: equ $-nameAsk
	hello: db "Hello "
	helloLen: equ $-hello
	
section .bss
	name resb 255
	
section .text
	global _start:
	
_start:
		mov eax, 4
		mov ebx, 1
		mov ecx, nameAsk
		mov edx, nameAskLen
		int 80h
		
		mov eax, 3
		mov ebx, 0
		mov ecx, name
		mov edx, 255
		int 80h
		
		mov eax, 4
		mov ebx, 1
		mov ecx, hello
		mov edx, helloLen
		int 80h
		
		mov eax, 4
		mov ebx, 1
		mov ecx, name
		mov edx, 255
		int 80h
		
		mov eax, 1
		mov ebx, 0
		int 80h