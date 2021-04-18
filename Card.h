#ifndef CARD_H
#define CARD_H

// Card class - represents a single card in the deck
class Card {
	
	// Data Members [PRIVATE]
	int value; 			// (1 .. 13)
	char suit; 			// (Heart, Club, Diamond, Spade)
	Card *nextCard;		// pointer - points to the next card in deck
	
	public: // Member Functions [PUBLIC]
		// default constructor
		Card();
		
		// parameterized constructor
		Card(int value, char suit);

		// This function prints card's number & suit in specified format
		void print();
		
		// Getters & Setters
		// This function returns the value of a card
		int getValue();
		
		// This function returns the suit of a card
		char getSuit();
		
		// This function returns the pointer pointing to nextCard if exist 
		// else returns - NULL
		Card* getNextCard();
		
		/* This function sets the value of a card
		 * returns 1 - Success
		 * returns 0 - Failure
		*/
		int setValue(int value);
		
		/* This function sets the suit of a card
		 * returns 1 - Success
		 * returns 0 - Failure
		*/
		int setSuit(char suit);
		
		/* This function sets the nextCard in the deck
		 * returns 1 - Success
		 * returns 0 - Failure
		*/
		int setNextCard(Card *nextCardAdd);
};

#endif
