#include <iostream>
#include <vector>
#include "atm.h"


using namespace std;

void insertVector(vector<ATM>&); // fill out the data about the clients to vector

//void showVector(vector<ATM>&);

void checkVectorPIN(vector<ATM>&, int, int);  // check out the input data from user with existing data

int temp_bank_number;
int temp_pin_card;


int chooseBankFunc()
{
	cout << "** Select your bank: Daegu bank - 1, NH - 2, Woori - 3, Shinhan - 4, KB Kookmin - 5 **" << endl;
	cout << "Number: ";
	cin >> temp_bank_number;
	if (temp_bank_number >= 1 && temp_bank_number <= 5) // check if the user wrote correct number. 
	{
		return temp_bank_number;
	}
	else
	{
		cout << "Your number is incorrect. Please try again" << endl; //if no, then, write again
		temp_bank_number = chooseBankFunc();
	}

}

int main()
{
	vector<ATM> myClient;
	insertVector(myClient);
	//showVector(myClient);
	


	cout << "¾Ó³çÇÏ¼¼¿ä, ATMÀÔ´Ï´Ù! \n ***Please insert your card and Press enter -> " << endl;
	temp_bank_number = chooseBankFunc();

	cout << "PIN card number: ";
	cin >> temp_pin_card;

	checkVectorPIN(myClient, temp_pin_card, temp_bank_number);
	return 0;


}

void insertVector(vector<ATM>& newClient)
{
	const int numClient = 3;

	// saved data in arrays
	int ID_[numClient] = {1, 2, 3};
	string name_[numClient] = { "Marlowe Fox", "Gorwin Gore", "Leesa Carry"};
	int bank_number_[numClient] = {1, 2, 2};
	int pin_card_[numClient] = { 508121, 800121, 619121 };
	int password_[numClient] = { 6324, 1999, 1111 };
	int balance_[numClient] = { 2045, 35, 582 };

	for (int i = 0; i < numClient; i++)
	{
		// insert element by element to vector of ATM class
		int ID = ID_[i];
		string name = name_[i];
		int bank_number = bank_number_[i];
		int pin_card = pin_card_[i];
		int password = password_[i];
		int balance = balance_[i];

		ATM newUser(ID, name, bank_number, pin_card, password, balance);
		newClient.push_back(newUser);
	}
	

}

// showVector() function is for printing all data saved in vector.
// I created it in order to check if the vector stored correctly all client info
// ATM system should not show the information. This is why It is not called. 
void showVector(vector<ATM>& newClient)
{
	unsigned int vector_size = newClient.size();
	for (int i = 0; i < vector_size; i++)
	{
		cout << "Client name " << newClient[i].getName() << endl;
	}
}

void checkVectorPIN(vector<ATM>& newClient, int temp_pin_card, int temp_bank_number)
{
	unsigned int vector_size = newClient.size();
	int temp = 0; // flag for pin card and bank number error
	int temp2 = 0; //flag for password error
	int temp3 = 0; // flag for no show password error if there is mistake in pin_card or bank numb
	for (int i = 0; i < vector_size; i++)
	{
		if (newClient[i].getPIN() == temp_pin_card && newClient[i].getBank() == temp_bank_number)
		{
			cout << "Insert your password: ";
			int temp_password;
			cin >> temp_password;
			temp = 1;
			temp3 = 0;
			if (newClient[i].getPassword() == temp_password)
			{
				cout << endl;
				cout << "~~~Information is available~~~" << endl;
				cout << "Your Name: " << newClient[i].getName() << endl;
				cout << "Card Balance: " << newClient[i].getBalance() << " USD " << endl;
				temp2 = 1;
				
			}
			break; // stop to search further if client info is found 
		}
		else { temp3 = 1; }
		
	}
	if (temp == 0) //catching error flag and show the error message out of the for-loop
	{
		cout << endl;
		cout << "-- Error! Your PIN card or Bank number are not matched --" << endl;
	}
	if (temp2 == 0 && temp3 == 0)
	{
		cout << endl;
		cout << "-- Error! Your password is incorrect --" << endl;
	}
}