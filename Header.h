#pragma once

using namespace std;
#include <iostream>
#include<time.h>

const int SIZE = 10;

struct randomNode {					// declare outside of the classes so you can reuse them 
	int randomNumber;				// remember to change the structs to use the template data type    
	int occurrences;
	randomNode* next;
};

struct ascendingOrderedNode {
	int orderedNumber;
	ascendingOrderedNode* next;
};

class tenForward {
private:
	int occurArray[SIZE] = { 0 };
	randomNode* head, * tail;
	ascendingOrderedNode* Ahead, * Atail;
	bool searchedOccur;
public:
	tenForward() {
		head = NULL;
		tail = NULL;
		Ahead = NULL;
		searchedOccur = NULL;
	};

	~tenForward() { delete head; ; delete tail; delete Ahead; };

	void populateRandomList(int randNum) {
		bool linearSearchCheck = false;
		linearSearchCheck = randLinearSearch(head, randNum);

		randomNode* current;
		current = head;

		if (linearSearchCheck == true) {

			searchOccur(randNum);

			occurArray[randNum - 1] += 1;

			while (current != NULL) {
				if (current->randomNumber == randNum) {
					current->occurrences = occurArray[randNum - 1];
				}
				current = current->next;
			}

		}
		else {
			randomNode* temp = new randomNode;
			temp->randomNumber = randNum;
			temp->next = NULL;

			searchOccur(randNum);

			occurArray[randNum - 1] += 1;
			temp->occurrences = occurArray[randNum - 1];

			if (head == NULL) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}
	}

	void populateOrderedList(int randNum) {
		bool linearSearchCheck = false;
		linearSearchCheck = ordLinearSearch(Ahead, randNum);

		ascendingOrderedNode* temp = new ascendingOrderedNode;
		temp->orderedNumber = randNum;

		ascendingOrderedNode* current = new ascendingOrderedNode;
		current->orderedNumber = randNum;
		current->next = NULL;

		if (linearSearchCheck == true) {

			return;

		}
		else {
			if (Ahead == NULL) {
				Ahead = current;
				Atail = current;
			}
			else if (Ahead->orderedNumber < randNum && Atail->orderedNumber < randNum) {
				Atail->next = current;
				Atail = current;
			}
			else if (Ahead->orderedNumber < randNum && Atail->orderedNumber > randNum) {
				Ahead = insertInMiddle(Ahead, randNum);
			}
			else {
				temp->next = Ahead;
				Ahead = temp;
			}
		}
	}

	void print(int randNum) {
		randomNode* current;
		current = head;

		ascendingOrderedNode* Acurrent;
		Acurrent = Ahead;

		cout << "Random Number: " << randNum << endl;

		if (searchedOccur == true) {
			cout << randNum << " IS in the list\n";
		}
		else {
			cout << randNum << " is NOT in the list\n";
		}

		cout << "Random Order:\n";

		while (current != NULL) {
			cout << current->randomNumber << " - " << current->occurrences << " occurrences\n";
			current = current->next;

		}
		cout << endl << "Order Ascending: ";

		while (Acurrent != NULL) {
			cout << Acurrent->orderedNumber << " ";
			Acurrent = Acurrent->next;
		}
		cout << endl;
	}

	void searchOccur(int numToSearch) {
		if (occurArray[numToSearch - 1] > 0) {
			searchedOccur = true;
		}
		else {
			searchedOccur = false;
		}
	}

	// searches list to test if new generated number is already in list
	bool randLinearSearch(randomNode* head, int randNum) {
		randomNode* current;
		current = head;

		while (current != NULL) {
			if (current->randomNumber == randNum) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool ordLinearSearch(ascendingOrderedNode* Ahead, int randNum) {
		ascendingOrderedNode* current;
		current = Ahead;

		while (current != NULL) {
			if (current->orderedNumber == randNum) {
				return true;
			}
			current = current->next;
		}
		return false;
	}

	ascendingOrderedNode* insertInMiddle(ascendingOrderedNode* Ahead, int randNum) {

		ascendingOrderedNode* current;
		current = Ahead;

		ascendingOrderedNode* temp = new ascendingOrderedNode;
		ascendingOrderedNode* temp1 = new ascendingOrderedNode;

		ascendingOrderedNode* tempHead = new ascendingOrderedNode;
		ascendingOrderedNode* tempHead1 = new ascendingOrderedNode;
		ascendingOrderedNode* tempTail = new ascendingOrderedNode;
		ascendingOrderedNode* tempTail1 = new ascendingOrderedNode;

		temp->orderedNumber = randNum;
		temp1->orderedNumber = randNum;

		tempHead = NULL;
		tempHead1 = NULL;
		tempTail = NULL;
		tempTail1 = NULL;

		while (current != NULL) {
			if (current->orderedNumber < randNum) {

				if (tempHead == NULL) {
					tempHead = current;
					tempTail = current;
				}
				else if (tempHead->orderedNumber < randNum && tempTail->orderedNumber < randNum) {
					tempTail->next = current;
					tempTail = current;
				}
				/*else {
					temp->next = tempHead;
					tempTail1 = temp;
				}*/

			}
			else if (current->orderedNumber > randNum) {

				if (tempHead1 == NULL) {
					tempHead1 = current;
					tempTail1 = current;
				}
				else if (tempHead1->orderedNumber < randNum && tempTail1->orderedNumber < randNum) {
					tempTail1->next = current;
					tempTail1 = current;
				}
				else {
					temp1->next = tempHead1;
					tempTail->next = temp1;
				}

			}
			current = current->next;
		}
		return tempHead;
	}
};

int generateRandNum() {
	return rand() % 10 + 1;
}


