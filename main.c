// PABLO
// DIA 29/08/2024, 10:25:40am -> Criação da função DecPraBi
// DIA 29/08/2024, 5:47:05pm -> Criação da função DecPraOcta
// DIA 30/08/2024, 8:24:15am -> Criação da função DecPraHexa 
// DIA 30/08/2024, 9:03:20am -> Criação da função DecPraBCD
// DIA 30/08/2024, 11:22:37am -> Criação da função DecPraComplemento2

#include <stdio.h>
#include <stdlib.h>

int DecPraBi(int decimal);
int DecPraOcta(int decimal);
int DecPraHexa(int decimal);
int DecPraBCD(int decimal);
void DecParaComplemento2(int decimal);

int main() {
  int numero;

  scanf("%d", &numero);

  DecPraBi(numero);
  DecPraOcta(numero);
  DecPraHexa(numero);
  DecPraBCD(numero);
  DecParaComplemento2(numero);

  return 0;
}

int DecPraBi(int decimal) {  
  int binario[32];
  int i = 0;

  if (decimal == 0) {
    return 0;
  }

  while (decimal > 0) {
      binario[i] = decimal % 2; 
      decimal = decimal / 2;   
      i++;
  }

  printf("Binário: ");
  for (int j = i - 1; j >= 0; j--) {
      printf("%d", binario[j]);
  }
  printf("\n");
  
  return 0;
}

int DecPraOcta(int decimal) {
  int octal[32];
  int i = 0;

  if (decimal == 0) {
    return 0;
  }  

  while (decimal > 0) {
    octal[i] = decimal % 8;
    decimal = decimal / 8;
    i++;
  }

  printf("Octal:");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", octal[j]);
  }
  printf("\n");
  
  return 0;
}

int DecPraHexa(int decimal) {
  int hexa[32];
  int i = 0;

  if (decimal == 0) {
    return 0;
  }

  while (decimal > 0) {
      int resto = decimal % 16;
      if (resto < 10) {
          hexa[i] = '0' + resto; 
      } else {
          hexa[i] = 'A' + (resto - 10);
      }
      decimal = decimal / 16;
      i++;
  }

  printf("Hexadecimal: ");
  for (int j = i - 1; j >= 0; j--) {
      printf("%c", hexa[j]);
  }
  printf("\n");
  
  return 0;
}

int DecPraBCD(int decimal) {
  
  if (decimal == 0) {
    return 0;
  }
  
   char bcd[4 * sizeof(decimal) + 1];
   int i = 0;

   while (decimal > 0) {
       int digito = decimal % 10;
       decimal = decimal / 10;

       for (int j = 3; j >= 0; j--) {
           bcd[i++] = (digito & (1 << j)) ? '1' : '0';
       }
   }

   printf("BCD: ");
   for (int j = i - 1; j >= 0; j--) {
       printf("%c", bcd[j]);
       if (j % 4 == 0 && j != i - 1) {
           printf(" ");
       }
   }
   printf("\n");
  
  return 0;
}

void DecParaComplemento2(int decimal) {
    int bits = 16;

  if (decimal >= 0) {
        unsigned int binario = decimal & 0xFFFF;

        printf("Complemento a 2 (positivo):");
        for (int i = bits - 1; i >= 0; i--) {
            printf("%d", (binario >> i) & 1);
            if (i % 4 == 0 && i != 0) {
                printf(" ");
            }
        }
        printf("\n");
    } else {
        unsigned int positivo = -decimal;
        unsigned int binario = ~positivo + 1;
        binario &= 0xFFFF;

        printf("Complemento a 2 (negativo):");
        for (int i = bits - 1; i >= 0; i--) {
            printf("%d", (binario >> i) & 1);
            if (i % 4 == 0 && i != 0) {
                printf(" ");
            }
        }
        printf("\n");
    }
}
