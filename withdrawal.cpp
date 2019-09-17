#include <iostream>
using namespace std;

int getInput();
void countBills(int amt );

int main()
{
	char goAgain = 'Y';
	int amt_in = 0;
	
	do { // get user input, perform calculations, ask to go again
	amt_in = getInput();
	countBills(amt_in);

	cout << "\nwould you like to make another withdrawal? (y/n) \n";
	cin >> goAgain;

	} while(goAgain == 'Y' || goAgain == 'y');
	cout << "Goodbye!\n";
	cout << '\n';
	return 0;
}

int getInput()// ask for input, if invalid print help and repeat
{
	int goodNum = 0;
	while(true) {
		cout << "\nhow much would you like to withdraw? \n";
		cin >> goodNum;
		if (goodNum >= 1 && goodNum <= 300) return goodNum;
		else cout <<"\n**requested amount must be between $1 and $300**\n";	
	}
}

void countBills(int amt)//check how many of each bill, save remainder, print 
{	
	int denom [5] = {50, 20, 10, 5, 1};
	int billCount = 0;
	int leftover = amt;
	int i=0;
	
	cout << "***************\n";
	for (i; i<5; i++){
		billCount = leftover / denom[i];
		leftover = leftover % denom[i];
		if (billCount == 1) cout  << billCount <<' '<< denom[i] << "\n";
		else if(billCount>1) cout<< billCount <<' '<< denom[i] << "'s\n";
	}
}
