.data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "%d\n"

  .text
  .globl main
  main:
  /* prologo */
     pushq %rbp
     movq  %rsp, %rbp
     subq  $16, %rsp
     movq  %rbx, -8(%rbp)
     movq  %r12, -16(%rbp)

  /* coloque seu codigo aqui */
    movl $0, %ebx        /* i = 0*/
    movq $nums, %r12     /* *p = nums */
  
  LOOP:
    cmpl  $5, %ebx       /* if ( i < 5 ) */
    jge F                 /* jump if greater or equal */
  
  
  /*Vc nao passa a funcao como parametro, 
  vc passa o retorno da fucncao*/

  /*
  int filtro(int x, int lim) {
  if (x < lim)
    return 0;
  else
    return x;
  }
  */
    movl (%r12), %edi  /* (x = *p) */
    movl $1, %esi    /* (lim = 1) */
    call filtro      /*  chama a funcao */

    /* o retorno da funcao sempre vai pro %eax*/

  /*printa*/
  
  /*************************************************************/
  /* este trecho imprime o valor de %eax (estraga %eax)        */
    movq    $s1, %rdi      /* primeiro parametro (ponteiro) */
    movl    %eax, %esi     /* segundo parametro  (inteiro) */
    call    printf         /* chama a funcao da biblioteca */
  /*************************************************************/
    
    addq $4, %r12        /* adiciona 4 bytes (p->pprox)*/
    addl  $1, %ebx       /* Soma 1 a i*/
    jmp LOOP             /* volta para o loop */

  F:
  /* finalizacao */
     movq -8(%rbp), %rbx
     movq -16(%rbp), %r12
     leave
     ret
