 // Name: life.cpp
// EE205 Homework 1 - task 2
// Team: RTS
// A program to play the game of life
#define GLIDER 1
#define SPACESHIP 2
#define EXPLODER 3
#define PERSON 4
#define FISH 5
#define ORG 1
#define DEAD 0
#define ISOLATION 2
#define JUST_RIGHT 3
#define CHANGE 5
#define NO_CHANGE 6
#define DIM 30
using namespace std;

void firstOrg(int grid[][DIM], int org){
    if(org == GLIDER){
        grid[5][5] = ORG;
        grid[5][4] = ORG;
        grid[5][6] = ORG;
        grid[4][6] = ORG;
        grid[3][5] = ORG;
    }
    else if(org == SPACESHIP){
        grid[3][3] = ORG;
        grid[3][2] = ORG;
        grid[3][4] = ORG;
        grid[3][5] = ORG;
        grid[4][5] = ORG;
        grid[5][5] = ORG;
        grid[6][4] = ORG;
        grid[4][1] = ORG;
        grid[6][1] = ORG;
    }
    else if(org == EXPLODER){
        grid[10][10] = ORG;
        grid[11][10] = ORG;
        grid[11][11] = ORG;
        grid[11][9] = ORG;
        grid[12][9] = ORG;
        grid[12][11] = ORG;
        grid[13][10] = ORG;
    }
    else if(org == PERSON){
        grid[2][4] = ORG;
        grid[3][4] = ORG;
        grid[4][4] = ORG;
        grid[4][3] = ORG;
        grid[4][5] = ORG;
        grid[5][4] = ORG;
        grid[6][3] = ORG;
        grid[6][5] = ORG;
        grid[7][3] = ORG;
        grid[7][5] = ORG;
    }
    else if(org == FISH){
        grid[2][4] = ORG;
        grid[3][5] = ORG;
        grid[4][4] = ORG;
        grid[3][3] = ORG;
        grid[2][2] = ORG;
        grid[3][2] = ORG;
        grid[4][2] = ORG;
    }
}

void bigRule(int grid[][DIM]){
  int tempGrid[DIM][DIM];
  int neighbors = 0;
  int status = 0;

  // Move original into copy
  for (int i = 0; i < DIM; ++i){
      for (int j = 0; j < DIM; ++j){
        tempGrid[i][j] = grid[i][j];
      }
  }

  // Rule 1
  for (int i = 0; i < DIM; ++i){
      for (int j = 0; j < DIM; ++j){
          //find neighbors
          if(grid[i-1][j-1] == ORG) neighbors++;
          if(grid[i-1][j] == ORG) neighbors++;
          if(grid[i][j-1] == ORG) neighbors++;
          if(grid[i-1][j+1] == ORG) neighbors++;
          if(grid[i+1][j-1] == ORG) neighbors++;
          if(grid[i+1][j] == ORG) neighbors++;
          if(grid[i][j+1] == ORG) neighbors++;
          if(grid[i+1][j+1] == ORG) neighbors++;

          //implement rules of life
          //new org spawned
          if(neighbors == JUST_RIGHT){
              tempGrid[i][j] = ORG;
              status++;
          }
          //reset neighbors
          neighbors = 0;
      }
  }

  // Rule 2
  for (int i = 0; i < DIM; ++i){
      for (int j = 0; j < DIM; ++j){
          int neighbors = 0;
          //find neighbors
          if(grid[i-1][j-1] == ORG) neighbors++;
          if(grid[i-1][j] == ORG) neighbors++;
          if(grid[i][j-1] == ORG) neighbors++;
          if(grid[i-1][j+1] == ORG) neighbors++;
          if(grid[i+1][j-1] == ORG) neighbors++;
          if(grid[i+1][j] == ORG) neighbors++;
          if(grid[i][j+1] == ORG) neighbors++;
          if(grid[i+1][j+1] == ORG) neighbors++;

          //implement rules of life
          if(neighbors < ISOLATION){
              tempGrid[i][j] = DEAD;
              status++;
          }
      }
  }

  // Rule 3
  for (int i = 0; i < DIM; ++i){
      for (int j = 0; j < DIM; ++j){
          int neighbors = 0;

          //find neighbors
          if(grid[i-1][j-1] == ORG) neighbors++;
          if(grid[i-1][j] == ORG) neighbors++;
          if(grid[i][j-1] == ORG) neighbors++;
          if(grid[i-1][j+1] == ORG) neighbors++;
          if(grid[i+1][j-1] == ORG) neighbors++;
          if(grid[i+1][j] == ORG) neighbors++;
          if(grid[i][j+1] == ORG) neighbors++;
          if(grid[i+1][j+1] == ORG) neighbors++;

          //implement rules of life
          if(neighbors > JUST_RIGHT){
              tempGrid[i][j] = DEAD;
              status++;
          }
      }
  }
  // Move copied grid into original
  for (int i = 0; i < DIM; ++i){
      for (int j = 0; j < DIM; ++j){
        if(tempGrid[i][j] != grid[i][j])
          grid[i][j] = tempGrid[i][j];
      }
  }
}

bool isEmpty(int grid[][DIM]){
  int count = 0;
  for(int j = 0; j < DIM; ++j){
    for(int k = 0; k < DIM; ++k){
      count += grid[j][k];
    }
  }
  if(count) return false;
  else return true;
}

int** arraycopy(int grid[DIM][DIM]){
    int** copy = 0;
    copy = new int*[DIM];

    for(int i = 0; i < DIM; i++){
        copy = new int*[DIM];
        for(int j = 0; j < DIM; j++){
            copy[i][j] = grid[i][j];
        }
    }
    return copy;
}
