#include <iostream>
using namespace std;

int avgGrid(int array[], int size){
  int iterator = 0, change = 2, old;
  while(change > 1){
    for(int i = 1; i < size; ++i){
      for(int j = 1; j < size; ++ j){
        old = array[i*size+j];
        array[i*size+j] = (array[i*size+j-1]+array[i*size+j+1]+array[i*(size+1)+j]+array[i*(size-1)+j])/4;
        change = array[i*size+j] - old;
      }
    }
    iterator += 1;
  }
  return iterator;
}
