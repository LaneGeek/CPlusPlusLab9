#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "BlackJackHand.hpp"

class Player {
private:
    // fields
    int stake;
    int bet;
protected:
    BlackJackHand *myHand;
public:
    // constructors
    Player();
    Player(int stake);

    // destructor
    ~Player();

    //setter
    void setStake(int stake);

    // getter
    int getStake();

    // method allowed to be overridden
    virtual std::string showHand();

    // other methods
    bool takeCard(PlayingCard *c);
    int getLowScore();
    int getHighScore();
    int getScore();
    bool busted();
    bool wantCard();
    void clearHand();
    bool makeBet(int bet);
    void won();
    void lost();
};

#endif
