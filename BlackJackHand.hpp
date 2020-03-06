#ifndef BLACKJACKHAND_HPP
#define BLACKJACKHAND_HPP

#include "PlayingCard.hpp"

class BlackJackHand {
private:
    const static int HANDSIZE = 5;
    PlayingCard *hand[HANDSIZE];
    int cardCount;
    int getCardIntValue(char value);
    std::string error;

public:
    BlackJackHand();
    BlackJackHand(PlayingCard *c1, PlayingCard *c2);
    ~BlackJackHand();
    bool addCard(PlayingCard *c1);
    int getCardCount();
    int getHighScore();
    int getLowScore();
    void clearHand();
    bool isBust();
    bool isFull();
    bool canTakeCard();
    std::string getAllCardCodes();
    std::string getError();
};

#endif
