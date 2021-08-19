
#define GETBIT(BUFFER, INDEX)                                                  \
  ((((BUFFER)[((INDEX) / 8)]) >> (7 - ((INDEX) % 8))) & 0x01)

#define SETBIT(BUFFER, INDEX)                                                  \
  (((BUFFER)[((INDEX) / 8)]) |= (0x01 << (7 - ((INDEX) % 8))))

#define CLRBIT(BUFFER, INDEX)                                                  \
  (((BUFFER)[((INDEX) / 8)]) &= ~(0x01 << (7 - ((INDEX) % 8))))

void des_e(char *dest, char *src);
