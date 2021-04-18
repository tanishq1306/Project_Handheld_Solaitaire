#include <bits/stdc++.h> 
#include "CardLL.h"
#define SUCCESS 1
#define FAILURE 0
#define DECK_SIZE 52
using namespace std;

//Definition of all the functions of CardLL class
CardLL::CardLL() {
	//cout << "CardLL - default constructor()\n";
	lenLL = 0;
	top = NULL;
}

CardLL::~CardLL() {
	//cout << "CardLL - destructor()\n";
	while (top != NULL) {
		Card* tempTop = top;
		top = top -> getNextCard();
		delete tempTop;
	}
		
	lenLL = 0;
	top = NULL;
}

int CardLL::insertAtTop(int value, char suit) {
	//cout << "CardLL - insertAtTop()\n";
	int status = FAILURE;
	
	Card *card = new Card(value, suit);
	if (card == NULL || value < 0 || value > 52 || suit < 'A' || suit > 'Z') {
		return status;	// memory is not allocated
	}
	
	card -> setNextCard(top);
	top = card;
	status = SUCCESS;
	lenLL++;
	
	return status;	// successfully inserted at top
}

Card* CardLL::getCardAt(int pos) {
	//cout << "CardLL - getCardAt()\n";
	assert(top != NULL && pos > 0 && pos <= lenLL);
	
	Card *tempTop = top;
	for (int i = 1;  i < pos; i++) {
		tempTop = tempTop -> getNextCard();
	}
	
	return tempTop;
}

int CardLL::removeCardAt(int pos) {
	//cout << "CardLL - removedCardAt()\n";
	assert(top != NULL);

	int status = FAILURE;
	if (pos <= 0 && pos > lenLL) {
		return status;
	}

	Card* tempTop = top;
	if (pos == 1) {		// remove top
		top = tempTop -> getNextCard();
		delete tempTop;
	}	
	else {
		pos--;
		while (pos > 1) {
			tempTop = tempTop -> getNextCard();
			pos--;
		}

		// remove element
		Card* nextCard = tempTop -> getNextCard() -> getNextCard();
		delete (tempTop -> getNextCard());
		tempTop -> setNextCard(nextCard);
	}

	lenLL--;
	status = SUCCESS;
	return status;
}

void CardLL::printLL() {
	// cout << "CardLL - printLL()\n";
	if (isEmpty()) {
		cout << "DECK EMPTY!!\n";
	}
	else {
		cout << "Top: ";
		Card *tempTop = top;
		for (int i = 1; i <= lenLL; i++) {
			tempTop -> print();
			tempTop = tempTop -> getNextCard();
		}
	}
	cout << "\n";
}

void CardLL::shuffle() {
	//cout << "CardLL - shuffle()\n";
	assert(top != NULL);
	
	vector<string> vShuffle;	// to store all cards
	Card *tempTop = top;
	
	// extract all cards from cardLL
	while (tempTop != NULL) {
		string c;
		c = to_string(tempTop -> getValue());
		c += tempTop -> getSuit();
		vShuffle.emplace_back(c);
		
		tempTop = tempTop -> getNextCard();
	}
	
	assert(vShuffle.size() == DECK_SIZE);
	
	// Fisher - Yates Shuffle Algorithm
	int indx = 0;
	srand((unsigned) time(0));
	for (indx = 0; indx < (int)DECK_SIZE; indx++) {
		int random_indx = (int)rand() % DECK_SIZE;
		swap(vShuffle[indx], vShuffle[random_indx]);
	}
	
	// map vShuffle to the actual cardLL deck
	tempTop = top;
	indx = 0;
	while (tempTop != NULL) {
		// extract out proper values of value and suit
		// from string format
		int value = vShuffle[indx][0] - '0';
		if ((int)vShuffle[indx].size() == 3) {
			value += vShuffle[indx][1] - '0';
		}
		char suit = vShuffle[indx].back();
		
		// update the values inside the cardLL / deck
		tempTop -> setValue(value);
		tempTop -> setSuit(suit);
		tempTop = tempTop -> getNextCard();
		indx++;
	}
}

int CardLL::getLength() {
	//cout << "CardLL - getLength()\n";
	return lenLL;
}

Card* CardLL::getTop() {
	//cout << "CardLL - getTop()\n";
	return top;
}

bool CardLL::isEmpty() {
	// cout << "CardLL - isEmpty()" << lenLL << this << "\n";
	if (lenLL == 0) {
		return true;
	}
	
	return false;
}
