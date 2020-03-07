#include "Dealer.hpp"

// constructors
Dealer::Dealer() {
    theDeck = new PlayingCardDeck();
}

Dealer::Dealer(int numShuffles) : Player(numShuffles) {
    theDeck = new PlayingCardDeck();
    theDeck->shuffle(numShuffles);
}

// destructor
Dealer::~Dealer() {
    delete theDeck;
}

std::string Dealer::showHand() {
    std::string output = myHand->getAllCardCodes();
    output = "XX " + output.substr(3, output.length() - 2);
    return output;
}

std::string Dealer::fullHand() {
    return myHand->getAllCardCodes();
}

PlayingCard *Dealer::dealCard() {
    PlayingCard *card = new PlayingCard();
    card = theDeck->dealCard();
    return card;
}

int Dealer::cardsLeft() {
    return theDeck->getCountRemain();
}

void Dealer::shuffle() {
    theDeck->shuffle(1);
}
