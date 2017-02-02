#include <iostream>
#include "prettyPrint.h"
using namespace std;

int avgGrid(int array[], int size){
  int iterator = 0, change = 2, curr = 0, prev = 0;

  // Until steady state is reached
  while(change > 1 || change < -1){
    prev = curr;
    curr = 0;

    // Iterate through array
    for(int i = 1; i < size-1; ++i){
      for(int j = 1; j < size-1; ++j){
        array[i*size+j] = (array[i*size+j-1]+array[i*size+j+1]+array[(i+1)*size+j]+array[(i-1)*size+j])/4;
        curr += array[i*size+j];
      }
    }
    // Count an interation
    iterator += 1;

    // Calculate the difference
    change = curr - prev;

    // Print the current array
    printMatrix(array, size, iterator);
  }
  return iterator;
}
