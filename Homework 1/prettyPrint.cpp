#include <iostream>
#define DIM 15
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

void printOrganisms(int grid[][DIM]){

    for (int i = 0; i < DIM; ++i){
        for (int j = 0; j < DIM; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}
