#include <iostream>
#include <string>
#include "basicAccount.h"
using namespace std;

basicAccount::basicAccount(){
}

basicAccount::basicAccount(basicAccount& copyAccount) {
	this->acctNum = copyAccount.acctNum;
	this->name = copyAccount.name;
	this->balance = copyAccount.balance;
}

void basicAccount::setAcctNum(long int id) {
	this->acctNum = id;
}

float basicAccount::getBalance() {
	return this->balance;
}
void basicAccount::setBalance(float value) {
	this->balance = value;
}
string basicAccount::getName() {
	return this->name;
}
void basicAccount::setName(string name) {
	this->name = name;
}
void basicAccount::deduct(float value) {
	this->balance -= value;
}
void basicAccount::deposit(float value) {
	this->balance += value;
}

void basicAccount::prettyPrint() {
	cout << this->getName() << "'s Account" << endl;
	cout << "Balance: " << this->getBalance() << endl;
	cout << endl;
}


void basicAccount::operator = (const basicAccount &b) {
	acctNum = b.acctNum;
	balance = b.balance;
	name = b.name;
}

bool basicAccount::operator == (const basicAccount &b) {
	if (
		name == b.name &&
		acctNum == b.acctNum &&
		balance == b.balance
		) return true;
	else return false;
}
