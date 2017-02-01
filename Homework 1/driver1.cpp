#include <iostream>
#include "stats.h"
using namespace std;

int main(){
  int n, t1, t2, t3, t4, tin, it, valid = 0;

  // Get size of square
  while(!valid){
    cout << "Please enter a square size (integer > 4): " << endl;
    try{
      cin >> n;
      if(n < 4) throw 1;
      else valid = 1;
    }
    catch(int fail) {
      cout << "Invalid entry" << endl;
    }
  }
  int grid[n*n];

  // Get edge temperatures
  cout << "Please enter 4 edge temperatures: " << endl;
  cin >> t1 >> t2 >> t3 >> t4;

  cout << "Please enter an inner temperature: " << endl;
  cin >> tin;
  int r = n;

  // Empty Array
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      grid[i*n+j] = 0;
    }
  }

  // Assign Temperatures
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i*n+j == 1*n+1) grid[i*n+j] = tin;       // First Inner
      if(i == 0) grid[i*n+j] = t1;                // Top side
      else if(j == n-1) grid[i*n+j] = t2;         // Right side
      else if(i == n-1) grid[i*n+j] = t3;         // Bottom side
      else if(j == 0) grid[i*n+j] = t4;           // Left side
    }
  }

  // Calculate
  it = avgGrid(grid, n);

  cout << it << " iterations" << endl;
  for(int i = 0; i < n*n; ++i){
    if(i%n == 0 && i != 0) cout << endl;
    cout << grid[i] << " ";
  }

  return 0;
}
