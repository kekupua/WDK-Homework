#include <iostream>
using namespace std;

void printMatrix(int array[], int size, int iterator){
  cout << endl << iterator << " iteration(s)" << endl;
  cout << "---------------" << endl;

  // Iterate through array
  for(int i = 0; i < size*size; ++i){
    if(i%size == 0 && i != 0) cout << "\t" << endl;
    cout << "\t" << array[i] << "\t";
  }
  cout << endl;

}
