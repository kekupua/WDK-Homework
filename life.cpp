//
// a program to play to play the game of life
//

#define ORG 1
#define DEAD 0
#include <iostream>

using namespace std;

void printgrid(int grid[10][10]);
void checkneighbors(int (*grid)[10][10]);

int main(){
    int life_grid[10][10];
    int (*p_grid)[10][10] = &life_grid;
    int x, y;
    int action;


    //initialize game of life matrix
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            life_grid[i][j] = 0;
            life_grid[i][j] = 0;
        }
    }
    
    //spawn first org in random location
    for(int i = 0; i < 8; i++){
        x = rand() % 10;
        y = rand() % 10;

        life_grid[x][y] = ORG;
    }
    
    //print out grid with initial orgs
    printgrid(life_grid);
    cout << endl;

    //an org is born in empty cells with exactly 3 neighbors
    //check for neighbors
    
    checkneighbors(p_grid); 

    //an org dies if it has less than 2 neighbors
    //check for neighbors
    
    //an org dies if it has more than 3 neighbors
    //check for neighbors

}


void printgrid(int grid[10][10]){

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

void checkneighbors(int (*grid)[10][10]){
    int neighbors = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            //find neighbors
            if(*grid[i][j] == ORG){
                if(*grid[i-1][j-1] == ORG) neighbors++;            
                if(*grid[i-1][j] == ORG) neighbors++;            
                if(*grid[i][j-1] == ORG) neighbors++;            
                if(*grid[i-1][j+1] == ORG) neighbors++;            
                if(*grid[i+1][j-1] == ORG) neighbors++;            
                if(*grid[i+1][j] == ORG) neighbors++;            
                if(*grid[i][j+1] == ORG) neighbors++;            
                if(*grid[i+1][j+1] == ORG) neighbors++;            
            }
            //implement rules of life
            if(neighbors == 3) *grid[i][j] = ORG;
            else if(neighbors < 2) *grid[i][j] = DEAD;
            else if(neighbors > 3) *grid[i][j] = DEAD;
            
            //reset neighbors
            neighbors = 0;
        }
    }
}

