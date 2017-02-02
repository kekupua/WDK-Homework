//
// a program to play to play the game of life
//

#define ORG 1
#define DEAD 0
#define ISOLATION 2
#define JUST_RIGHT 3
#define DONE 5
//#define USERIN

#include <iostream>

using namespace std;

void printgrid(int grid[10][10]);
int checkneighbors(int (&grid)[10][10]);

int main(){
    int life_grid[10][10];
    int (&p_grid)[10][10] = life_grid;
    int x, y;
    int i_org = 0;
    int status = 0;

#ifdef USERIN
    //ask for number of starting organisms
    cout << "How many initial organisms?" << endl;
    cin >> i_org;
#endif

    //initialize game of life matrix
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            life_grid[i][j] = DEAD;
            life_grid[i][j] = DEAD;
        }
    }

    i_org = 12;
    //spawn first orgs in random locations
    for(int i = 0; i <= i_org; i++){
        x = rand() % 10;
        y = rand() % 10;
        if(life_grid[x][y] != ORG){
            life_grid[x][y] = ORG;
        }
        else i--;
    }

    //print out grid with initial orgs
    printgrid(life_grid);
    cout << endl;


    while(1){
        //an org is born in empty cells with exactly 3 neighbors
        //an org dies if it has less than 2 neighbors
        //an org dies if it has more than 3 neighbors
        //check for neighbors
        status = checkneighbors(p_grid);
        if(status == DONE) break;

        //print out new grid
        printgrid(life_grid);
        cout << endl;
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

int checkneighbors(int (&grid)[10][10]){
    int neighbors = 0;
    int flag = 0;
    int orgs = 0;

    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            //how many orgs left?
            if(grid[i][j] == ORG) orgs++;

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
            if(neighbors == JUST_RIGHT) grid[i][j] = ORG;
            //org dies
            else if(neighbors < ISOLATION) grid[i][j] = DEAD;
            else if(neighbors > JUST_RIGHT) grid[i][j] = DEAD;
            else flag++;

            //reset neighbors
            neighbors = 0;
        }
    }
    //done if no more rules to be implemented
    if(flag == orgs*2) return DONE;
    else return 0;
}


