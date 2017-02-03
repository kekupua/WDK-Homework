#include <iostream>
#include "life.h"
#include "prettyPrint.h"

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
#define DIM 15

using namespace std;

int main(){
    int life[DIM][DIM];
    int i_org = 0;
    int status = 0;

    //ask for starting organism
    cout << "Which organism would you like to start with?" << endl;
    cout << "Enter (1) for glider" << endl;
    cout << "Enter (2) for spaceship" << endl;
    cout << "Enter (3) for exploder" << endl;
    cout << "Enter (4) for person" << endl;
    cout << "Enter (5) for fish" << endl;
    cin >> i_org;

    //initialize game of life matrix
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            life[i][j] = DEAD;
            life[i][j] = DEAD;
        }
    }

    //intialize organism
    firstOrg(life, i_org);

    //print out life with initial orgs
    printOrganisms(life);
    cout << endl;


    for(int i = 0; i < 5; i++){
        //grid_cpy cause seg fault
        //aggggh!
        //grid_cpy = arraycopy(grid);

        //an org is born in empty cells with exactly 3 neighbors
        status = rule1(life);

        if(status == CHANGE){
            //print out new grid
            //printOrganisms(life);
            cout << endl;
        }
        //an org dies if it has less than 2 neighbors
        status = rule2(life);

        if(status == CHANGE){
            //print out new grid
            //printOrganisms(life);
            cout << endl;
        }

        //an org dies if it has more than 3 neighbors
        status = rule3(life);

        if(status == CHANGE){
            //print out new grid
            //printOrganisms(life);
            cout << endl;
        }
        printOrganisms(life);
    }

}
