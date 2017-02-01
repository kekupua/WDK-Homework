#include <iostream>
using namespace std;

int avgGrid(int array[], int size){
  int iterator = 0, change = 2, old;
  while(change > 1 || change < -1){
    old = array[1*size+1];
    for(int i = 1; i < size-1; ++i){
      for(int j = 1; j < size; ++ j){
        //old = array[i*size+j];
        array[i*size+j] = (array[i*size+j-1]+array[i*size+j+1]+array[(i+1)*size+j]+array[(i-1)*size+j])/4;
        //change = array[i*size+j] - old;
      }
    }
    iterator += 1;
    change = array[1*size+1] - old;
    cout << change << endl;
  }
  return iterator;
}
