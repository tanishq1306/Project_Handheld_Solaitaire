#include <bits/stdc++.h> 
#include "CardLL.cpp"
#include "Card.cpp"

/** Constants **/
const int RANK = 13;
const int HOUSES = 4;
const char suits[HOUSES] = {'S', 'H', 'C', 'D'};
using namespace std;

/** Utility Functions **/
int populateDeck(CardLL &cardLL);
void tryValueMatch(CardLL &onDeckTable);
void trySuitMatch(CardLL &onDeckTable);
void play(CardLL &playingDeck);

int main() {
	char choice;
	do {
		system("cls");
		CardLL playingDeck;
		
		// populate deck and check for exception
		assert(populateDeck(playingDeck) != FAILURE);
		
		// shuffle 
		playingDeck.shuffle();
		
		// let's play
		play(playingDeck);
		
		// destructor called
		playingDeck.~CardLL();
		
		
		cout << "Do You Want To Continue (Y / N) : ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	
	return 0;
}
 
int populateDeck(CardLL &cardLL) {
	for (char suit: suits) {
		for (int value = RANK; value >= 1; value--) {
			if (cardLL.insertAtTop(value, suit) == FAILURE) {
				return FAILURE;
			}
		}
	}

	return SUCCESS;
}

void tryValueMatch(CardLL &onDeckTable) {
	assert(onDeckTable.getTop() != NULL);

	int value_1 = onDeckTable.getTop() -> getValue();
	Card* tempTop = onDeckTable.getTop();

	for (int i = 1; i <= 3; i++) {
		tempTop = tempTop -> getNextCard();
	}
	
	int value_2 = tempTop -> getValue();
	if (value_1 == value_2) {
		// discard all four on top
		cout <<"Number Match! Removing: ";
		cout << (onDeckTable.getTop() -> getValue()) << (onDeckTable.getTop() -> getSuit()) << " ";
		onDeckTable.removeCardAt(1);
		
		cout << (onDeckTable.getTop() -> getValue()) << (onDeckTable.getTop() -> getSuit()) << " ";
		onDeckTable.removeCardAt(1);
		
		cout << (onDeckTable.getTop() -> getValue()) << (onDeckTable.getTop() -> getSuit()) << " ";
		onDeckTable.removeCardAt(1);
		
		cout << (onDeckTable.getTop() -> getValue()) << (onDeckTable.getTop() -> getSuit()) << " ";
		onDeckTable.removeCardAt(1);
		
		cout << "\n\n";
	}
}

void trySuitMatch(CardLL &onDeckTable) {	
	assert(onDeckTable.getTop() != NULL);

	char suit_1 = onDeckTable.getTop() -> getSuit();
	Card* tempTop = onDeckTable.getTop();

	for (int i = 1; i <= 3; i++) {
		tempTop = tempTop -> getNextCard();
	}

	char suit_2 = tempTop -> getSuit();
	if (suit_1 == suit_2) {
		// discard two middle cards
		cout <<"Suite Match! Removing: ";
		cout << (onDeckTable.getCardAt(2) -> getValue()) << (onDeckTable.getCardAt(2) -> getSuit()) << " ";
		onDeckTable.removeCardAt(2);
		
		cout << (onDeckTable.getCardAt(2) -> getValue()) << (onDeckTable.getCardAt(2) -> getSuit()) << " ";
		onDeckTable.removeCardAt(2);
		
		cout << "\n\n";
	}
}

void play(CardLL &playingDeck) {
	/* Inside Play
	 * -----------
	 * Pick one card from deck
	 * Check with the 3 back card if exists
	 	* CASE 1 : when VALUES matches discard all 4 cards
		* CASE 2 : when SUITS matches discard only 2 middle cards
	*/
	
	int finalScore = 0;
	Card* tempTop = playingDeck.getTop();
	CardLL onTableDeck;
		
	for (int i = 1; i <= DECK_SIZE; i++) {
		onTableDeck.insertAtTop(tempTop -> getValue(), tempTop -> getSuit());
		onTableDeck.printLL();
		
		if (onTableDeck.getLength() >= 4) {	
			tryValueMatch(onTableDeck);
		}
		
		if (onTableDeck.getLength() >= 4) {	
			trySuitMatch(onTableDeck);
		}
		
		tempTop = tempTop -> getNextCard();
	}
	
	finalScore = onTableDeck.getLength();
	cout << "\n\t\t\t ------------------------\n";
	cout << "\t\t\t| Final Score : " << finalScore << "       |\n";
	cout << "\t\t\t|  THANK YOU FOR PLAYING |\n";
	cout << "\t\t\t ------------------------\n\n";
}
