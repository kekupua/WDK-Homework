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
#define DIM 30

using namespace std;

int main(){
    int life[DIM][DIM];
    int i_org = 0;
    int status = 0;

    // Ask for starting organism
    cout << "Which organism would you like to start with?" << endl;
    cout << "Enter (1) for glider" << endl;
    cout << "Enter (2) for spaceship" << endl;
    cout << "Enter (3) for exploder" << endl;
    cout << "Enter (4) for person" << endl;
    cout << "Enter (5) for fish" << endl;
    cin >> i_org;

    // Initialize game of life matrix
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            life[i][j] = DEAD;
            life[i][j] = DEAD;
        }
    }

    // Intialize organism
    firstOrg(life, i_org);

    // Print out life with initial orgs
    printOrganisms(life);
    cout << endl;

    // Printing of the Grid
    for(int i = 0; i < 40; i++){
        bigRule(life);
        cout << endl;
        printOrganisms(life);
        if(isEmpty(life)) break;
    }

    return 0;
}
