#include "Player.hpp"

// constructors
Player::Player() {
    myHand = new BlackJackHand();
    stake = 0;
}

Player::Player(int stake) {
    this->stake = stake;
}

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

// other methods
bool Player::takeCard(PlayingCard *c) {
    myHand->addCard(c);
}

std::string Player::showHand() {
    return myHand->getAllCardCodes();
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
    return getHighScore() > 21;
}

bool Player::wantCard() {
    return getScore() < 16;
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
