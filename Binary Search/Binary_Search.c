#include "Binary_Search.h"

int binary_search(int a, const int *array, int array_size) {
  int left = 0;
  int right = array_size -1;
  int mid;

  while(left <= right) {
    mid = (left+right)/2;
    if(array[mid] == a)
      return 1;
    else if(array[mid] > a)
      right = mid-1;
    else
      left = mid+1;
  }

  return 0;
}
