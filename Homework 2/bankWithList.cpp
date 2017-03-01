#define CREATE 1
#define FIND 2
#define DELETE 3
#define PRINT 4
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "basicAccount.h"
#include "singlyLinked.h"
using namespace std;

int main(){
  SinglyLinkedList s;

  while(1){
    int action;
    cout << "\nAction:\n(1) Create Account\n(2) Find Customer\n(3) Delete Customer\n(4) Print All\n";
    cin >> action;

    // Create account
    if(action == CREATE){
      string name;
      float balance;
      long int ID;

      // User input
    	cout << "Enter a name: " << endl;
    	cin >> name;
      cout << "Enter a balance: " << endl;
      cin >> balance;
      cout << "Enter an ID: " << endl;
      cin >> ID;

    	// Create necessary objects
    	basicAccount* info = new basicAccount(ID, name, balance);
    	SLink* link = new SLink(info);

      // Attempt to insert
      int status = s.addB(link);
      if(!status){ delete link; delete info;}
      cout << endl;
      s.print_all();
    }

    //Find Account
    else if(action == FIND){
      string query;
      cout << "Search by Name or Account Number: " << endl;
      cin >> query;
      if(isdigit(query[0])){
        long int search = atoi(query.c_str());
        s.findB(search);
      }
      else s.findB(query);
      cout << endl;
      s.print_all();
    }

    // Delete Account
    else if(action == DELETE){
      string query;
      cout << "Delete by Name or Account Number: " << endl;
      cin >> query;
      if(isdigit(query[0])){
        long int search = atoi(query.c_str());
        s.deleteB(search);
      }
      else s.deleteB(query);
      cout << endl;
      s.print_all();
    }

    else if(action == PRINT){
      s.print_all();
    }

    // Invalid input
    else{
      cout << endl << "Invalid rule, try again." << endl;
    }

  }
  return 0;
}
