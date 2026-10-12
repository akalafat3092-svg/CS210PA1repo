#pragma once
#include <ostream>
#include <string>
#include "Stack.h"
#include "Card.h"
// Hello
class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }
    void drawCard(Card* card) {
        hand_.push(card);
    }
    Card* playCard() {
        return hand_.pop();
    }
    Card* topCard() const {
        return hand_.peek();
    }
    void printHand() const {
        hand_.print();
    }
    int handSize() const {
        return hand_.size();
    }

private:
    int id_;
    std::string name_;
    Stack<Card> hand_;
};
