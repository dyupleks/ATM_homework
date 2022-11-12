#ifndef ATM_H //library
#define ATM_H

#include <iostream>
#include <string>

using namespace std;

class ATM {
public:   // public access modifier
	ATM(); // constructor
	ATM(int, string, int, int, int, int); // overload constructor for initialization for objects of class
	int getID() const; // accessor functions for returning object values. 'const' means no modification
	string getName() const; // accessor functions
	int getPIN() const; // accessor functions
	int getPassword() const; // accessor functions
	int getBalance() const; // accessor functions
	int getBank() const; // accessor functions
	 
private: // private access modifier
	int newID;
	string newName;
	int newBank_number;
	int newPin_card;
	int newPassword;
	int newBalance;

};

#endif
