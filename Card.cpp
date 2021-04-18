#include <bits/stdc++.h> 
#include "Card.h"
#define SUCCESS 1
#define FAILURE 0
using namespace std;

//Definition of all the functions of class Card
Card::Card() {
	//cout << "Card - default constructor()\n";
	value = 0;
	suit = '0';
	nextCard = NULL;
}; 

Card::Card(int value, char suit) {
	//cout << "Card - parameterized constructor()\n";
	assert(value >= 1 && value <= 13);
	this -> value = value;
	
	assert(suit == 'H' || suit == 'D' || suit == 'C' || suit == 'S');
	this -> suit = suit;
	
	nextCard = NULL;
}

void Card::print() {
	//cout << "Card - print()\n";
	assert(this != NULL);	// assertion card is not null	
	
	if (this -> value == 1) {
		cout << 'A';
	}
	else if (this -> value < 10) {
		cout << this -> value;
	}
	else if (this -> value == 10) {
		cout << 'T';
	}
	else if (this -> value == 11) {
		cout << 'J';
	}
	else if (this -> value == 12) {
		cout << 'Q';
	}
	else if (this -> value == 13) {
		cout << 'K';
	}
	
	cout << this -> suit << " ";
}

int Card::setValue(int value) {
	//cout << "Card - setValue()\n";
	assert(this != NULL);
	
	int status = FAILURE;
	if (value >= 1 && value <= 13) {
		status = SUCCESS;
		this -> value = value;
	}
	
	return status;
}

int Card::setSuit(char suit) {
	//cout << "Card - setSuit()\n";
	assert(this != NULL);
	
	int status = FAILURE;
	if (suit >= 'A' && suit <= 'Z') {
		status = SUCCESS;
		this -> suit = suit;
	}
	
	return status;
}

int Card::setNextCard(Card *nextCardAdd) {
	//cout << "Card - setNextCard()\n";
	assert(this != NULL);
	
	int status = FAILURE;
	if (nextCardAdd != NULL) {
		status = SUCCESS;	
		this -> nextCard = nextCardAdd;
	}
	
	return status;
}

int Card::getValue() {
	//cout << "Card - getValue()\n";
	assert(this != NULL);
	
	return value;
}

char Card::getSuit() {
	//cout << "Card - getSuit()\n";
	assert(this != NULL);
	
	return suit;
}

Card* Card::getNextCard() {
	//cout << "Card - getNextCard()\n";
	assert(this != NULL);
	
	if (this -> nextCard != NULL) {
		return (this -> nextCard);
	}
	
	return NULL;	// if the next card doesn't exist
}
