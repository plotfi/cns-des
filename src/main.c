
/***************************************\

               Puyan Lotfi
                 gtg945h
                CS 4803

\***************************************/

#include <stdio.h>

#ifdef DO_DES
#include "my_des.h"
#endif

#ifdef DO_IDEA
#include "my_idea.h"
#endif

int main(int argv, char **argc) {

#ifdef DO_DES
  int i;
  long long puyan;
  char clearText[8];
  char cypherText[8];
  char *nayup;
#endif

#ifdef DO_IDEA
  long long input;
#endif

#ifdef DO_DES

#ifdef TEST
  char test = {0, 0, 0, 0, 0, 0, 12, 171};
#endif

  printf("Enter input in decimal: ");
  scanf("%lld", &puyan);

  nayup = (char *)(&puyan);

  const int a = 0x1;

  if (((const char *)&a)[0]) {

    clearText[0] = nayup[7];
    clearText[1] = nayup[6];
    clearText[2] = nayup[5];
    clearText[3] = nayup[4];
    clearText[4] = nayup[3];
    clearText[5] = nayup[2];
    clearText[6] = nayup[1];
    clearText[7] = nayup[0];
  } else {
    for (i = 0; i < 8; i++) {
      clearText[i] = nayup[i];
    }
  }

  des_e(cypherText, clearText);

#ifdef TEST
  des_e(cypherText, test);
#endif

#endif

#ifdef CRYPT_ASCII_DES

  for (i = 0; i < 8; i++) {

    printf("%c", clearText[i]);
  }

  printf("\n");

  for (i = 0; i < 8; i++) {

    printf("%c", cypherText[i]);
  }

  printf("\n");

#endif

#ifdef CRYPT_BINARY_DES

  printf("Clear  Text (Binary): ");

  for (i = 0; i < 64; i++) {
    printf("%d", GETBIT(clearText, i));
  }

  printf("\n");

  printf("Cypher Text (Binary): ");

  for (i = 0; i < 64; i++) {
    printf("%d", GETBIT(cypherText, i));
  }

  printf("\n");

#endif

#ifdef DO_IDEA

  printf("Enter data in decimal: ");
  scanf("%lld", &input);
  printf("Clear  Text (Decimal): %lld\n", input);
  printf("Cypher Text (Decimal): %lld\n", idea_e(input));

#endif

  return 0;
}
