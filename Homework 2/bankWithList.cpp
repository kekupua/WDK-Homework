#define CREATE 1
#define FIND 2
#define DELETE 3
#define PRINT 4
#include <iostream>
#include <string>
#include "basicAccount.h"
#include "doublyLinked.h"
using namespace std;

int main(){
  DoublyLinkedList d;
  long int ID;
  while(1){
    int action;
    cout << "\nAction:\n(1) Create Account\n(2) Find Customer\n(3) Delete Customer\n(4) Print All\n";
    cin >> action;

    // Create account
    if(action == CREATE){
      string name;
      float balance;
      cout << "Enter a name and balance" << endl;
      cin >> name >> balance >> ID;
      basicAccount* info = new basicAccount(ID, name, balance);
      DLink* link = new DLink(info);
      int status = d.addB(link);
      if(!status){delete link; delete info;}
    }

    // Find Account
    else if(action == FIND){

    }

    // Delete Account
    else if(action == DELETE){

    }

    else if(action == PRINT){
      if(d.getHead() == NULL) cout << "Empty List!" << endl;
      d.print_all(d.getHead());
    }

    // Invalid input
    else{
      cout << endl << "Invalid rule, try again." << endl;
    }

  }
  return 0;
}
