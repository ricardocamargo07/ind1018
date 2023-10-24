/*  Tradução da funcao add  em um arquivo separado */
/*
    int add (int a, int b, int c) {
        return a+b+c;
    }
*/
.global add
add:
    movl %edi, %eax
    addl %esi, %eax 
    addl %edx, %eax 
    ret
    