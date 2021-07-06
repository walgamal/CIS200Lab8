#include "Header.h"

int main() {

	cout << "Welcome to the Random Linked List Sorter\n";
	cout << "This program generate 10 random numbers display information about them\n";
	system("pause");
	cout << endl;


	srand(time(NULL));

	tenForward a;

	for (int i = 0; i < SIZE; i++) {
		int tempNum = 0;
		tempNum = generateRandNum();

		cout << "------------------------------------------------------\n";

		a.populateRandomList(tempNum);
		a.populateOrderedList(tempNum);
		a.print(tempNum);


		cout << "------------------------------------------------------\n";
	}

	return 0;
}



