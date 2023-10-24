
/*int main(void){
    for(int i =1; i<=10;i++){
      A = I *I
        printf("%d\n",A);
    }
    return 0;
}*/


.data
Sf:  .string "%d\n"    # String de formato para printf

.text
.globl  main
main:

/********************************************************/
/* Mantenha este trecho aqui e não mexa - prólogo!!!    */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

  movl  $1, %ebx     /* eax = 1; */

L1:
  cmpl  $10, %eax    /* if (ebx >= 10) ? */
  
  jg L2            /* goto L2 */
  
  imull  %eax, %eax  /* eax*eax */

  movl  %eax, %ebx  /* ebx = eax*/

/*************************************************************/
/* Este trecho imprime o valor de %eax (estraga %eax)        */
  pushq   %rcx       /* Salva o valor de rcx */
  movq    $Sf, %rdi  /* Primeiro parâmetro (ponteiro)   */
  movl    %ebx, %esi   /* Segundo parâmetro (inteiro)    */
  call    printf     /* Chama a função da biblioteca    */
  popq    %rcx       /* Restaura o valor de rcx após a chamada */
/*************************************************************/

  addl  $1, %eax     /* ebx += 1; */
  
  jmp  L1            /* goto L1; */


L2:
/***************************************************************/
/* Mantenha este trecho aqui e não mexa - finalização!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/
