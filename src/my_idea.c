
/*                      *\
     Puyan Lotfi
      gtg945h
      CS 4803
\*                     */

#include "my_idea.h"
#include <stdio.h>

long long idea_e(const long long input) {
  long long Ke = 0x1234LL;
  long long Kf = 0x5678LL;

  return doEvenRound(input, Ke, Kf);
}

static long long modifiedAdd(const long long a, const long long b) {
  return ((a + b) % 0x10000);
}

static long long modifiedMultiply(const long long a, const long long b) {
  return ((a * b) % (0x10000 + 1));
}

static long long doEvenRound(const long long inputData, const long long Ke,
                             const long long Kf) {
  long long Xa = (inputData >> (16 * 3)) & 0x0000000000000000ffff;
  long long Xb = ((inputData << 16) >> (16 * 3)) & 0x000000000000ffff;
  long long Xc = ((inputData << (16 * 2)) >> (16 * 3)) & 0x000000000000ffff;
  long long Xd = ((inputData << (16 * 3)) >> (16 * 3)) & 0x000000000000ffff;

  long long Yin = Xa ^ Xb;
  long long Zin = Xc ^ Xd;

  long long Yout =
      modifiedMultiply(modifiedAdd(modifiedMultiply(Ke, Yin), Zin), Kf);
  long long Zout = modifiedAdd(modifiedMultiply(Ke, Yin), Yout);

  Xa = Xa ^ Yout;
  Xb = Xb ^ Yout;
  Xc = Xc ^ Zout;
  Xd = Xd ^ Zout;

  long long encryptedInput = (Xa << 48 | Xb << 32 | Xc << 16 | Xd);
  return encryptedInput;
}
