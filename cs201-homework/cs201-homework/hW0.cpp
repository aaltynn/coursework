#include <iostream>
using namespace std;
int main() {
	double balance;
	double transaction;
	double amount;
	cout << "Enter your current balance: ";
	cin >> balance;
	cout << "Enter transaction type (1 for deposit, 2 for withdrawal): ";
	cin >> transaction;

	if (transaction == 1)
	{
		cout << "Enter amount: ";
		cin >> amount;
		balance = balance + amount;
		cout << "Transaction successful. Your new balance is: " << balance << endl;
	}
	else if (transaction == 2)
	{
		cout << "Enter amount: ";
		cin >> amount;
		balance = balance - amount;
		if (balance >= 0)
		{
			cout << "Transaction successful. Your new balance is: " << balance << endl;
		}
		else
		{
			cout << "Insufficient funds. Transaction failed.";
		}

	}
	else
	{
		cout << "Invalid transaction type. ";
	}

	return 0;
}