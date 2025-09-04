// Troca de Vetor I
// Faça um programa que leia um vetor N[20]. Troque a seguir, o primeiro elemento com o último, o segundo elemento com o penúltimo, etc., até trocar o 10º com o 11º. Mostre o vetor modificado.

#include <stdio.h>
#define MAX_VETOR 20

int main()
{

  int N[MAX_VETOR];
  int i;
  int temp;

  for (i = 0; i < MAX_VETOR; i++)
  {
    scanf("%d", &N[i]);
  }

  for (i = 0; i < MAX_VETOR / 2; i++)
  {
    temp = N[i];
    N[i] = N[MAX_VETOR - 1 - i];
    N[MAX_VETOR - 1 - i] = temp;
  }

  for (i = 0; i < MAX_VETOR; i++)
  {
    printf("N[%d] = %d\n", i, N[i]);
  }

  return 0;
}
