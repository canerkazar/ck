

// ################################################################
// ###################  CANER KAZAR - 201334006 ###################
// ###################     DOGUS UNIVERSITY     ###################
// ############################ 2016 ##############################


#include<iostream>
#include<string>
#include <cstdlib>
#include<stdlib.h>

using namespace std;
double s = 0;
class Account
{
private:
	string name;
	long int accountNumber;
	double balance;
	string name2 = "Ahmet";
	long int accountNumber2 = 1334018;
	double balance2 = 2000;
public:
	void account(string Aname, long int Aacno, double Abalance);
	void setBalance(double Abalance);
	double getBalance();
	double deposit(double quantity);
	double withdraw(double wdraw);
	void moneyTransfer(long int accountNumber2, double tmoney);
	void accountinf();
};



void Account::account(string Aname, long int Aacno, double Abalance)
{
	name = Aname;
	accountNumber = Aacno;
	balance = Abalance;
	cout << "\nYour Name : " << name << endl;
	cout << "Your Account Number :  " << accountNumber << endl;
	cout << "Your Balance : " << balance << endl;


}
void Account::accountinf()
{
	cout << "\nYour Name : " << name << endl;
	cout << "Your Account Number :  " << accountNumber << endl;
	cout << "Your Balance : " << balance << endl;
	cout << "2. Account Name : " << name2 << endl;
	cout << "2. Account No : " << accountNumber2 << endl;
	cout << "2. Account Balance :" << balance2 << endl;
}

void Account::setBalance(double Abalance)
{
	balance = Abalance;
	cout << "\nBalance Updated";
}

double Account::getBalance()
{
	return balance;
}

double Account::deposit(double quantity)
{
	balance += quantity;
	cout << "\nYour deposit completed.\n";
	cout << "\nNew TL balance is : " << balance << endl;
	return balance;
}

double Account::withdraw(double wdraw)
{
	if (balance <= 0 || balance < wdraw)
	{
		cout << "\nNo enough money, please try again\n";
	}
	else
	{
		balance -= wdraw;
		cout << "\nYour draw completed.\n";
		cout << "\nNew TL balance is : " << balance << endl;
	}
	return balance;
}

void Account::moneyTransfer(long int accountNumber2, double tmoney)
{
	int x = 1334018;
	if (tmoney > balance || accountNumber2 != x)
	{
		cout << "\nInsufficient Funds...\n";
		cout << "\nPlease enter o account number which is tranfer to money : ";
		cin >> accountNumber2;
		cout << "\nEnter the amount of money: ";
		cin >> tmoney;

	}
	if (tmoney < balance && accountNumber2 == x)
	{
		balance -= tmoney;
		balance2 += tmoney;
		cout << "\nTransfer is completed...\n";
	}
}


class DollarCurrencyAccount : private Account
{
private:
	double dolarBalance = 0;
	double dolarBalance2 = 0;
public:
	double Ddeposit(double Dquantity);
	double Dwithdraw(double Dwdraw);
	double Dexchange();
	void Dtransfer(double Dtr, long int Dacno2);
};
/*---------------------------------------------------------------------------------*/
double DollarCurrencyAccount::Ddeposit(double Dquantity)
{
	dolarBalance += Dquantity;
	cout << "\nYour dollar deposit completed.\n";
	cout << "\nNew dollar balance is : " << dolarBalance << endl;
	return dolarBalance;
}
double DollarCurrencyAccount::Dwithdraw(double Dwdraw)
{
	if (dolarBalance <= 0 || dolarBalance < Dwdraw)
	{
		cout << "\nNo enough money, please try again\n";
	}
	else
	{
		dolarBalance -= Dwdraw;
		cout << "\nYour dollar draw completed.\n";
		cout << "\nNew dollar balance is : " << dolarBalance << endl;
	}
	return dolarBalance;
}
double DollarCurrencyAccount::Dexchange()
{

	double d;
	cout << "\nYour current dollar balance is : " << dolarBalance << endl;
	cout << "\nExchange Rate : 1 Dollar = 4.09 TL\n";
	cout << "\nHow much do you prefer to exchange ? : ";
	cin >> d;
	if (dolarBalance <= 0 || dolarBalance < d)
	{
		cout << "\nNo enough money, please try again\n";
	}
	else
	{
		dolarBalance -= d;
		s = d*4.09;
		cout << "\nYour dollar exchange completed.\n";
		cout << "\nNew dollar balance is : " << dolarBalance << endl;

	}
	return dolarBalance;

}
void DollarCurrencyAccount::Dtransfer(double Dtr, long int Dacno2)
{
	int x = 1334018;
	if (Dtr > dolarBalance || Dacno2 != x)
	{
		cout << "\nInsufficient Funds...\n";
		cout << "\nPlease enter o account number which is tranfer to money : ";
		cin >> Dacno2;
		cout << "\nEnter the amount of money: ";
		cin >> Dtr;

	}
	if (Dtr < dolarBalance && Dacno2 == x)
	{
		dolarBalance -= Dtr;
		dolarBalance2 += Dtr;
		cout << "\nTransfer is completed...\n";
	}
}

/*--------------------------------------------------------------------------------*/
int main()
{
	char ch, ch1, ch2;
	long int accountNumber2, Dacno2, Acno;
	double tmoney, Dtr, balance, num;
	string name;
	Account myac;
	DollarCurrencyAccount myca;
	do
	{
		cout << "\n01. CREATE ACCOUNT\n";
		cout << "02. DEPOSIT AMOUNT\n";
		cout << "03. WITHDRAW AMOUNT\n";
		cout << "04. SET BALANCE \n";
		cout << "05. GET BALANCE \n";
		cout << "06. DOLLAR CURRENCY ACCOUNT\n";
		cout << "07. MONEY TRANSFER\n";
		cout << "08. ACCOUNT INFORMATION\n";
		cout << "09. EXIT\n";
		cout << "\nSelect Your Option (1-8) \n";
		cin >> ch;
		switch (ch)
		{
		case '1':
			cout << "\nWrite Your Name : ";
			cin >> name;
			cout << "Write Account Number : ";
			cin >> Acno;
			cout << "Write Balance : ";
			cin >> balance;
			myac.account(name, Acno, balance);
			break;
		case '2':
			cout << "\nEnter The amount to be deposited : ";
			cin >> num;
			myac.deposit(num);
			break;
		case '3':
			cout << "\nEnter The amount to be withdraw : ";
			cin >> num;
			myac.withdraw(num);
			break;
		case '4':
			cout << "\nEnter The amount balance : ";
			cin >> num;
			myac.setBalance(num);
			break;
		case '5':
			cout << "\nYour Balance Is : " << myac.getBalance() << endl;
			break;
		case '6':
			cout << "\nWhich foreign currency account would you open? \n" << endl;

			do
			{
				cout << "\n01. Dollar\n";
				cout << "02. EXIT\n";
				cin >> ch1;
				switch (ch1)
				{
				case'1':
					cout << "\n01. Deposit\n";
					cout << "02. Withdraw\n";
					cout << "03. Transfer\n";
					cout << "04. Exchange\n";
					cout << "05. EXIT\n";
					cin >> ch2;
					switch (ch2)
					do
					{
					case'1':
						cout << "\nEnter The amount to be dollar deposited : ";
						cin >> num;
						myca.Ddeposit(num);
						break;
					case'2':
						cout << "\nEnter The amount to be dollar withdraw : ";
						cin >> num;
						myca.Dwithdraw(num);
						break;
					case'3':
						cout << "\nPlease enter o account number which is tranfer to money : ";
						cin >> Dacno2;
						cout << "\nEnter the amount of money: ";
						cin >> Dtr;
						myca.Dtransfer(Dacno2, Dtr);
						break;
					case'4':
						myca.Dexchange();
						myac.deposit(s);
						break;
					} while (ch2 != '5');

					break;

				}

			} while (ch1 != '2');

			break;
		case '7':
			cout << "\nPlease enter o account number which is tranfer to money : ";
			cin >> accountNumber2;
			cout << "\nEnter the amount of money: ";
			cin >> tmoney;
			myac.moneyTransfer(accountNumber2, tmoney);
			break;
		case '8':
			myac.accountinf();
			break;
		case '9':
			cout << "\nThanks for using bank management system";
			break;
		default:cout << "Select Your Option (1-8) \n";
		}

	} while (ch != '9');
	return 0;

}



