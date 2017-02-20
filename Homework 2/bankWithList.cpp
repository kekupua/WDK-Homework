#include <iostream>
#include "basicAccount.h"
#include "doublyLinked.h"

int main(){
  DoublyLinkedList d;
  basicAccount bFirst(1,"A", 2000.50);
  DLink dFirst(bFirst);

  
  cout << dFirst.b.getBalance() << endl;

  return 0;
}
