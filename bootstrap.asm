; Os42 Bootstrap

; Declare Multiboot Constants
MBALIGN		equ		1<<0
MEMINFO		equ		1<<1
FLAGS		equ		MBALIGN | MEMINFO	; Multiboot flags
MAGIC		equ		0x1BADB002			; Magic for multiboot
CHECKSUM	equ		-(MAGIC + FLAGS)	; Checksum of multiboot header

; Multiboot Header Declaration
section .multiboot:
align 4
	dd MAGIC
	dd FLAGS
	dd CHECKSUM
	
; Bootstrap Stack Space (BS Stack)
section .bs_stack:
align 4
	bs_stack_bottom:
	times 16384 db 0
	bs_stack_top:

; Entry Point
section .text:
global _entry
_entry:

	; Setup the stack
	mov esp, bs_stack_top
	mov ebp, bs_stack_top
	
	; Call the kernel
	extern kernel_main
	call kernel_main
	
	cli

.hang:
	hlt
	jmp .hang
