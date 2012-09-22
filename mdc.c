/*
  Maximo divisor comum
  Romulo Pereira (romuloccomp@gmail.com)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int mdc(int a,int b);
int pprimo(p);

void main(){
  int a,b;
  char op;
  do{
    printf("Informe dois numeros inteiros: ");
    scanf("%i%i",&a,&b);
    printf("m.d.c => %i\n",mdc(a,b));
    printf("\nDeseja calcular outro mdc? ");
    scanf("%s",&op);
  }while((op=='s')||(op=='S')); 
  
  system("Pause");
  return;
}

/* Medoto de Euclides estendido
 * para calcular o MDC
 */
int mdc(int a,int b){
  if(b == 0) 
    return a;
  else
    return mdc(b,a%b);
}

/* Verificar se um número é
 * primo
 */
int pprimo(p)
{
 int k,sqrtp;
 sqrtp = sqrt(p);
 k=2;
 while ((k<=sqrtp) && ((p%k) != 0))
 k++;
 if (k >= sqrtp) return 1;
 else return 0;
}