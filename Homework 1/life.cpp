// 
// Name: life.cpp
// EE205 Homework 1 - task 2
// Team: RTS
// A program to play the game of life
//

#define GLIDER 1
#define SPACESHIP 2
#define EXPLODER 3
#define ORG 1
#define DEAD 0
#define ISOLATION 2
#define JUST_RIGHT 3
#define CHANGE 5
#define NO_CHANGE 6


#include <iostream>

using namespace std;

void printgrid(int grid[10][10]);
void firstorg(int (&grid)[10][10], int org);
//void checkneighbors(int (&grid)[10][10]);
int rule1(int (&grid)[10][10]);
int rule2(int (&grid)[10][10]);
int rule3(int (&grid)[10][10]);

int main(){
    int life_grid[10][10];
    int (&p_grid)[10][10] = life_grid;
    int x, y;
    int i_org = 0;
    int status = 0;

    //ask for starting organism
    cout << "Which organism would you like to start with?" << endl;
    cout << "Enter 1 for glider" << endl;
    cout << "Enter 2 for spaceship" << endl;
    cout << "Enter 3 for exploder" << endl;
    cin >> i_org;

    //initialize game of life matrix
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            life_grid[i][j] = DEAD;
            life_grid[i][j] = DEAD;
        }
    }
    
    //intialize organism
    firstorg(life_grid, i_org);

    //print out grid with initial orgs
    printgrid(life_grid);
    cout << endl;


    for(int i = 0; i < 3; i++){
        //an org is born in empty cells with exactly 3 neighbors
        status = rule1(p_grid);
        
        if(status == CHANGE){
            //print out new grid
            printgrid(life_grid);
            cout << endl;
        }
        //an org dies if it has less than 2 neighbors
        status = rule2(p_grid);
        
        if(status == CHANGE){
            //print out new grid
            printgrid(life_grid);
            cout << endl;
        }
        
        //an org dies if it has more than 3 neighbors
        status = rule3(p_grid);
        
        if(status == CHANGE){
            //print out new grid
            printgrid(life_grid);
            cout << endl;
        }
    }

}


void printgrid(int grid[10][10]){

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

void firstorg(int (&grid)[10][10], int org){
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
        grid[2][4] = ORG;
        grid[3][4] = ORG;
        grid[4][4] = ORG;
        grid[4][5] = ORG;
        grid[4][3] = ORG;
        grid[5][3] = ORG;
        grid[5][5] = ORG;
        grid[6][4] = ORG;
    }
}

int rule1(int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            
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
                grid[i][j] = ORG;
                status++;
            }
            //reset neighbors
            neighbors = 0;
        }
    }
    if(status != 0) return CHANGE;
    else return NO_CHANGE;
}


int rule2(int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            
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
                grid[i][j] = DEAD;
                status++;
            }
            //reset neighbors
            neighbors = 0;
        }
    }
    if(status != 0) return CHANGE;
    else return NO_CHANGE;
}

int rule3(int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            
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
                grid[i][j] = DEAD;
                status++;
            }
            //reset neighbors
            neighbors = 0;
        }
    }
    if(status != 0) return CHANGE;
    else return NO_CHANGE;
}
