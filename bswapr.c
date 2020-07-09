/*
 Copyright (c) 2020 Rolando González Chévere <rolosworld@gmail.com>
*/
#include <stdio.h>
#include <stdint.h>

void bswapr(void* bytes, size_t bytes_len) {
  if (bytes == NULL || bytes_len < 2) {
    return;
  }

  uint8_t* first = (uint8_t*) bytes;
  uint8_t* last = first + bytes_len - 1;

  while (first != last && first < last) {
    *first ^= *last ^= *first ^= *last;
    first++;
    last--;
  }
}

int main() {
  int a = 123;
  printf("a %d\n", a);
  bswapr(&a, sizeof(a));
  printf("a %d\n", a);
  bswapr(&a, sizeof(a));
  printf("a %d\n", a);

  uint8_t b = 9;
  printf("b %d\n", b);
  bswapr(&b, sizeof(b));
  printf("b %d\n", b);
  bswapr(&b, sizeof(b));
  printf("b %d\n", b);

  uint64_t c = 123;
  printf("c %ld\n", c);
  bswapr(&c, sizeof(c));
  printf("c %ld\n", c);
  bswapr(&c, sizeof(c));
  printf("c %ld\n", c);
  
  return 1;
}
