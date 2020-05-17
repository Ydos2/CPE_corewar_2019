    .name "ristas"
    .comment "get issoued"

    ld %1, r2
    ld %3, r3
    st r1, r2
    sti r1, %:issou_protect, %1
    sti r1, %:attack, %1
issou_protect:
    live %84
    ld %150, r4
    sub r3, r4, r4
    fork r4
attack: ld %80, r3
    live %84
    ld %50, r3
    ld 30, r4
    sub r3, r4, r3
    live %84
    st r3, 162
    st r3, 173
    st r3, 184
    st r3, 195
    st r3, 206
    ld 100, r4
    zjmp %:issou_protect
    add r3, r4, r3
    st r3, 127
    st r3, 129
    st r3, 184
    st r3, 195
    st r3, 206
    zjmp %:attack

issou_shield:
    ld %30, r4
    live %84
    sub r3, r4, r7
    fork r7
    live %84
