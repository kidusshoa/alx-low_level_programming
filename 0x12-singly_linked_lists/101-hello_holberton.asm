 section .data
    hello db 'Hello, Holberton',0

section .text
    global main
    extern printf

main:
    push rdi           ; Preserve the value of rdi register
    mov rdi, hello     ; Load the address of the string into rdi
    call printf        ; Call printf function
    pop rdi            ; Restore the value of rdi register

    ; Exit the program
    mov rax, 60        ; syscall: exit
    xor rdi, rdi       ; status: 0
    syscall

