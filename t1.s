.data
str:    .asciz "Hello World!\n"   
len = 13                   

.text
.global main

main:
    mov r0, #0                  
    ldr r1, =str        
           
loop:
    ldrb r2, [r1], #1            
    mov r7, #4                   
    mov r0, #1                                 
    mov r3, #1                   
    swi 0                        
    add r0, r0, #1               
    add r3, r3, #1               
    cmp r3, #len                  
    blt loop                     

exit:
    mov r7, #1                   
    mov r0, #0                   
    swi 0