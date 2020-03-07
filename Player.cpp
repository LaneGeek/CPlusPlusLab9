#include "Player.hpp"

// constructors
Player::Player() {
    myHand = new BlackJackHand();
    stake = 0;
}

Player::Player(int stake) {
    myHand = new BlackJackHand();
    this->stake = stake;
}

// destructor
Player::~Player() {
    delete myHand;
}

// setter
void Player::setStake(int stake) {
    this->stake = stake;
}

// getter
int Player::getStake() {
    return stake;
}

// method allowed to be overridden
std::string Player::showHand() {
    return myHand->getAllCardCodes();
}

// other methods
bool Player::takeCard(PlayingCard *c) {
    return myHand->addCard(c);
}

int Player::getLowScore() {
    return myHand->getLowScore();
}

int Player::getHighScore() {
    return myHand->getHighScore();
}

int Player::getScore() {
    return getHighScore() > 21 ? getHighScore() : getLowScore();
}

bool Player::busted() {
    return myHand->isBust();
}

bool Player::wantCard() {
    return getHighScore() < 16;
}

void Player::clearHand() {
    myHand->clearHand();
}

bool Player::makeBet(int bet) {
    if (bet < stake) {
        this->bet = bet;
        return true;
    }
    return false;
}

void Player::won() {
    stake += bet;
}

void Player::lost() {
    stake -= bet;
}
