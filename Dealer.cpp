#include "Dealer.hpp"

// constructors
Dealer::Dealer() {
    theDeck = new PlayingCardDeck;
}

Dealer::Dealer(int numShuffles) : Player(numShuffles) {
    theDeck = new PlayingCardDeck;
    theDeck->shuffle(numShuffles);
}

// destructor
Dealer::~Dealer() {
    delete theDeck;
}

// overridden method
std::string Dealer::showHand() {
    std::string output = myHand->getAllCardCodes();
    output = "XX " + output.substr(3, output.length() - 2);
    return output;
}

// other methods
std::string Dealer::fullHand() {
    return myHand->getAllCardCodes();
}

PlayingCard *Dealer::dealCard() {
    PlayingCard *card = theDeck->dealCard();
    return card;
}

int Dealer::cardsLeft() {
    return theDeck->getCountRemain();
}

void Dealer::shuffle() {
    // delete the old deck
    delete theDeck;
    // create a new deck and shuffle it once
    theDeck = new PlayingCardDeck(1);
}
