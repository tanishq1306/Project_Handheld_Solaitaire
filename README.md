# Project_Handheld_Solaitaire_Tanishq

## Introduction to assignment 

**Handheld Solitaire** is an automated game & requires no table, has simple rules, and is easy to play. It is played with a traditional 52 card deck of 4 suits (hearts, clubs, diamonds, and spades) and 13 ranks from ace (1) to king (13). Jokers are not included.

**Game Play**
   *	Pick a card from the top of the deck of 52 cards.
   *	When a match occurs between the top card and the card 3 back from it, either in rank or suit do:
   *	If the ranks match, all 4 top cards of the hand are discarded.
   *	If the suits match, only the middle 2 (of the top 4) cards of the hand are discarded. 
   *	The final score is the number of cards left in the hand at the end of the game. 

## Requirements specifications of the assignment 
   Handheld Solitaire is developed in **C++ using OOP's Concept**. 

## Implementation 
*Card.h*

```
class Card {
   Data Member
     int value;
     char suit;
     Card *nextCard;

   Member Functions
     Card();
     Card(int value, char suit);
     void print();
     int getValue();
     char getSuit();
     Card* getNextCard();
     int setValue(int value);
     int setSuit(char suit);
     int setNextCard(Card *nextCardAdd); 
}
```

*CardLL.h*

```
class CardLL {
  Data Members
    int lenLL;
    Card *top;
   
  Member Functions
    CardLL();
    ~CardLL();
    int insertAtTop(int value, char suit);
    Card* getCardAt(int pos);
    int removeCardAt(int pos);
    void printLL();
    void shuffle();
    int getLength();
    Card* getTop();
    bool isEmpty();	
}
```
> Function definitions are written in *card.cpp* and *cardLL.cpp* <br>
> Driver Main Function is written inside *HHSolaitiare.cpp*

## Output Screenshots
### Testrun_1
<img src = "https://github.com/tanishq1306/Project_Handheld_Solaitaire/blob/main/testrun_1.PNG">

### Testrun_2
<img src = "https://github.com/tanishq1306/Project_Handheld_Solaitaire/blob/main/testrun_2.PNG">

### Testrun_3
<img src = "https://github.com/tanishq1306/Project_Handheld_Solaitaire/blob/main/testrun_3.PNG">
