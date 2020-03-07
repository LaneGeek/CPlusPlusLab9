#ifndef DEALER_HPP
#define DEALER_HPP

#include "Player.hpp"
#include "PlayingCardDeck.hpp"

class Dealer : public Player {
    // fields
    PlayingCardDeck *theDeck;
public:
    // constructors
    Dealer();
    Dealer(int numShuffles);

    // destructor
    ~Dealer();

    std::string showHand() override;

    std::string fullHand();

    PlayingCard *dealCard();

    int cardsLeft();

    void shuffle();
};

#endif
