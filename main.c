// PABLO
// DIA 30/08/2024, 9:03:20am

#include <stdio.h>
#include <stdlib.h>

int DecPraBi(int decimal);
int DecPraOcta(int decimal);
int DecPraHexa(int decimal);
int DecPraBCD(int decimal);

int main() {
  int numero;

  scanf("%d", &numero);

  DecPraBi(numero);
  DecPraOcta(numero);
  DecPraHexa(numero);
  DecPraBCD(numero);

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
