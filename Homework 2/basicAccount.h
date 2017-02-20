#ifndef BASIC_H
#define BASIC_H

#include <string>
using namespace std;
class basicAccount {
public:
	basicAccount();
	basicAccount(long int id, string n, float bal) : acctNum(id), name(n), balance(bal) {}
	basicAccount(basicAccount& copyAccount);

	void setAcctNum(long int id);

	float getBalance();
	void setBalance(float value);

	string getName();
	void setName(string name);

	void deduct(float value);
	void deposit(float value);
	void prettyPrint();


	void operator = (const basicAccount &b);
	bool operator == (const basicAccount &b);

private:
	long int acctNum;
	string name;
	float balance;
};

#endif
