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

void printGrid(int grid[10][10]){

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}
