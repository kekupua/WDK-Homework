#include <iostream>
#include "life.h"
#include "prettyPrint.h"

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

int main(){
    int life_grid[10][10];
    int (&p_grid)[10][10] = life_grid;
    int x, y;
    int i_org = 0;
    int status = 0;

    //ask for starting organism
    cout << "Which organism would you like to start with?" << endl;
    cout << "Enter (1) for glider" << endl;
    cout << "Enter (2) for spaceship" << endl;
    cout << "Enter (3) for exploder" << endl;
    cout << "Enter (4) for person" << endl;
    cout << "Enter (5) for small exploder" << endl;
    cin >> i_org;

    //initialize game of life matrix
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            life_grid[i][j] = DEAD;
            life_grid[i][j] = DEAD;
        }
    }

    //intialize organism
    firstOrg(life_grid, i_org);

    //print out grid with initial orgs
    printGrid(life_grid);
    cout << endl;


    for(int i = 0; i < 3; i++){
        //an org is born in empty cells with exactly 3 neighbors
        status = rule1(p_grid);

        if(status == CHANGE){
            //print out new grid
            printGrid(life_grid);
            cout << endl;
        }
        //an org dies if it has less than 2 neighbors
        status = rule2(p_grid);

        if(status == CHANGE){
            //print out new grid
            printGrid(life_grid);
            cout << endl;
        }

        //an org dies if it has more than 3 neighbors
        status = rule3(p_grid);

        if(status == CHANGE){
            //print out new grid
            printGrid(life_grid);
            cout << endl;
        }
    }

}
