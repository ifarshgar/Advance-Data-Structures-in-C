#include "Sequential_Search.h"

int sequential_search(int a, const int *array, int array_size) {
  for(int i=0; i<array_size; i++) {
    if(a == array[i])
      return 1;
  }

  return 0;
}
