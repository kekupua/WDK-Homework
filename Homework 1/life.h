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
#define ITERATIONS 25
void firstOrg(int grid[][DIM], int org);
void bigRule(int grid[][DIM]);
bool isEmpty(int grid[][DIM]);
