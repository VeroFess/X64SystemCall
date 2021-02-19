.code

memset	proc
    xor     rax, rax
memset_loop:
    cmp     rax, r8
    je      memset_end
    mov     [rcx + rax], dl
    inc     rax
    jmp     memset_loop
memset_end:
    mov     rax, rcx
    ret
memset  endp

memcpy	proc
    push r9
    xor     rax, rax
memcpy_loop:
    cmp     rax, r8
    je      memcpy_end
    mov     r9, [rdx + rax]
    mov     [rcx + rax], r9
    inc     rax
    jmp     memcpy_loop
memcpy_end:
    mov     rax, rcx
    pop     r9
    ret
memcpy  endp

end