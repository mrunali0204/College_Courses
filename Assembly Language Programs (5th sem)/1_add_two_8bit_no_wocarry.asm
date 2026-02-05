.model small
.stack 100h
.code
main proc
    mov al, 25h
    mov bl, 34h
    add al, bl
    mov ah, 4Ch
    int 21h
main endp
end main
