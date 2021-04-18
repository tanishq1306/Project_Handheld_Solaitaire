#ifndef CARDLL_H
#define CARDLL_H
#include "Card.h"

// CardLL class - represents the Linked List / deck of class Card
class CardLL {
	// Data Members [PRIVATE]
	int lenLL;	// length of the linked list
	Card *top;	// points to the top of the linked list / deck
	
	public:	// Member Functions [PUBLIC]
		// default constructor			
		CardLL();
		
		// default destructor
		~CardLL();
		
		/* This function inserts a new card at the top of the deck
		 * returns 1 - Success 
		 * returns 0 - Failure 
		 */
		int insertAtTop(int value, char suit);
		
		/* This function returns the pointer pointing to the card required 
		 * returns NULL if pos is INVALID
		 */
		Card* getCardAt(int pos);
		
		/* This function removes the card at given position
		 * returns 1 - Removed Successfully
		 * returns 0 - Failure (Ex- might be possible that pos is INVALID)
		 */ 
		int removeCardAt(int pos);
		
		/* This function prints list of card that are currently in deck
		 * prints - "EMPTY" if the list is empty
		 */ 
		void printLL();
		
		// This function shuffles the card in deck  
		void shuffle();
		
		/* This function returns length - list of card that are in deck
		 * returns 0 - if the list is empty
		 */ 
		int getLength();
		
		/* This function returns top pointer
		 * returns NULL - if the list is empty
		 */ 
		Card* getTop();
		
		/* This function 
		 * returns true - if list is empty else 
		 * returns false - list not empty
		*/ 
		bool isEmpty();	
};

#endif
