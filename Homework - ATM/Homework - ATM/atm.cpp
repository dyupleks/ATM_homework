#include "atm.h"

ATM::ATM(int ID, string name, int bank_number, int pin_card, int password, int balance) 
//class::constructor(type variables)
{
	newID = ID;
	newName = name;
	newBank_number = bank_number;
	newPin_card = pin_card;
	newPassword = password;
	newBalance = balance;

}

int ATM::getID() const { // calling accessor function from atm.h and return newID
	return newID;
}

string ATM::getName() const { // calling accessor function from atm.h and return newName
	return newName;
}

int ATM::getBank() const { // calling accessor function from atm.h and return newBank_number
	return newBank_number;
}

int ATM::getPIN() const { // calling accessor function from atm.h and return newPin_card
	return newPin_card;
}

int ATM::getPassword() const { // calling accessor function from atm.h and return newPassword
	return newPassword;
}

int ATM::getBalance() const { // calling accessor function from atm.h and return newBalance
	return newBalance;
}