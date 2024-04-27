.global bubble_sort

bubble_sort:
    push {r4, r5, r6, lr}   ; 保存寄存器状态

    mov r5, r1              ; r5 = 数组首地址
    mov r6, r2              ; r6 = 数组元素个数

outer_loop:
    mov r4, #0              ; r4 = 0
    mov r2, r6              ; r2 = 数组元素个数

inner_loop:
    ldrb r0, [r5], #1       ; r0 = a[j]
    ldrb r3, [r5]           ; r3 = a[j+1]
    cmp r0, r3              ; 比较 a[j] 和 a[j+1]
    ble no_swap             ; 如果 a[j] <= a[j+1]，跳过交换

    strb r3, [r5, #-1]      ; 交换 a[j] 和 a[j+1]
    strb r0, [r5]
    mov r4, #1              ; 标记本轮有交换发生

no_swap:
    subs r2, r2, #1         ; r2--
    cmp r2, #1
    bne inner_loop          ; 继续内层循环

    cmp r4, #0              ; 如果本轮没有交换发生，说明数组已经有序
    beq exit                ; 跳出外层循环

    subs r6, r6, #1         ; r6--
    mov r5, r1              ; 重置数组首地址
    b outer_loop             ; 继续外层循环

exit:
    pop {r4, r5, r6, pc}    ; 恢复寄存器状态并返回
