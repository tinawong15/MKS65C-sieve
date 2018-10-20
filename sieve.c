# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "sieve.h"

int sieve(int targetPrime) {
  int size;
  if(targetPrime > 5000) {
    size = targetPrime * log(targetPrime) * 1.15;
  }
  else {
    size = targetPrime * log(targetPrime) * 1.30 + 10;
  }
  int * numbers = calloc(sizeof(int), size);
  int c;
  int c2;
  // 0 if prime
  // 1 if composite
  int prime_counter = 0;
  // printf("%d\n", size);
  for(c = 2; c <= size; c++) {
    if(numbers[c] == 0) {
      prime_counter++;
      // printf("prim ctr: %d\n", prime_counter);
      if(prime_counter == targetPrime) {
        return c;
      }
      for(c2 = c; c2+c <= size; c2+=c) {
        numbers[c2+c] = 1;
      }
    }
  }
  // int test;
  // for(test = 0; test < size; test++) {
  //   printf("Index %d: %d\n", test, numbers[test]);
  // }
  return 0;
}

// int main() {
//   printf("%d\n", sieve(1000000));
//   return 0;
// }
