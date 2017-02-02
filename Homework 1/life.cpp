 // Name: life.cpp
// EE205 Homework 1 - task 2
// Team: RTS
// A program to play the game of life
#define GLIDER 1
#define SPACESHIP 2
#define EXPLODER 3
#define PERSON 4
#define SMALLEXPLODER 5
#define ORG 1
#define DEAD 0
#define ISOLATION 2
#define JUST_RIGHT 3
#define CHANGE 5
#define NO_CHANGE 6

using namespace std;

void firstOrg(int (&grid)[10][10], int org){
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
    else if(org == PERSON){
        grid[2][4] = ORG;
        grid[3][4] = ORG;
        grid[4][4] = ORG;
        grid[4][3] = ORG;
        grid[4][5] = ORG;
        grid[5][4] = ORG;
        grid[6][3] = ORG;
        grid[6][5] = ORG;
    }
    else if(org == SMALLEXPLODER){
        grid[2][4] = ORG;
        grid[3][3] = ORG;
        grid[3][4] = ORG;
        grid[3][5] = ORG;
        grid[4][3] = ORG;
        grid[4][5] = ORG;
        grid[5][4] = ORG;
    }
}

int rule1(const int (&grid_ls)[10][10], int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){

            //find neighbors
            if(grid_ls[i-1][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j] == ORG) neighbors++;
            if(grid_ls[i][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j-1] == ORG) neighbors++;
            if(grid_ls[i+1][j] == ORG) neighbors++;
            if(grid_ls[i][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j+1] == ORG) neighbors++;

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


int rule2(const int (&grid_ls)[10][10], int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){

            //find neighbors
            if(grid_ls[i-1][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j] == ORG) neighbors++;
            if(grid_ls[i][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j-1] == ORG) neighbors++;
            if(grid_ls[i+1][j] == ORG) neighbors++;
            if(grid_ls[i][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j+1] == ORG) neighbors++;

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

int rule3(const int (&grid_ls)[10][10], int (&grid)[10][10]){
    int neighbors = 0;
    int status = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){

            //find neighbors
            if(grid_ls[i-1][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j] == ORG) neighbors++;
            if(grid_ls[i][j-1] == ORG) neighbors++;
            if(grid_ls[i-1][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j-1] == ORG) neighbors++;
            if(grid_ls[i+1][j] == ORG) neighbors++;
            if(grid_ls[i][j+1] == ORG) neighbors++;
            if(grid_ls[i+1][j+1] == ORG) neighbors++;

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
