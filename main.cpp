#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    /*std::unique_ptr<ArrayList<Player>> tableList = make_unique<ArrayList<Player>>();*/
    /*std::unique_ptr<LinkedList<Player>> tableList = make_unique<LinkedList<Player>>();*/
    std::unique_ptr<List<Player>> tableList = makeList<Player>();
    std::cout << "New Table Scene:" << std::endl;
    tableList->addFront(new Player(0, "Ike"));
    tableList->addFront(new Player(1, "Aykan"));
    tableList->addFront(new Player(2, "Icon"));
    tableList->addFront(new Player(3, "Enner"));
    tableList->print();
    std::cout << "New Player Joins aka addAnywhere(2):"<< std::endl;
    tableList->addAnywhere(2, new Player(4, "Jilio"));
    tableList->print();
    std::cout << "Someone plays the reverse card aka reverse():"<< std::endl;
    tableList->reverse();
    tableList->print();
    std::cout << "Someone Leaves the Table aka deleteAnywhere(1):"<< std::endl;
    tableList->deleteAnywhere(1);
    tableList->print();
    /*std::unique_ptr<ArrayList<Player>> otherTable = make_unique<ArrayList<Player>>();*/
    /*std::unique_ptr<List<Player>> otherTable = make_unique<LinkedList<Player>>();*/
    std::unique_ptr<List<Player>> otherTable = makeList<Player>();
    std::cout << "Other Table:"<< std::endl;
    otherTable->addFront(new Player(5, "Acorn"));
    otherTable->addFront(new Player(6, "Acorniston"));
    otherTable->addFront(new Player(7, "Ican"));
    otherTable->print();
    std::cout << "Other Table Joins Original aka concat():"<< std::endl;
    tableList->concat(otherTable.get());
    tableList->print();
    otherTable->print();

    std::cout << "---- EXTRA CREDIT SCENE ----" << std::endl;
    std::unique_ptr<List<Player>> extraTable = makeList<Player>();
    Player* halJ = new Player(10, "Hal Jordan");
    extraTable->addFront(halJ);
    halJ->drawCard(new Card("Green", "6"));
    halJ->drawCard(new Card("Red", "9"));
    halJ->drawCard(new Card("Green", "4"));
    halJ->drawCard(new Card("Red", "Reverse"));
    std::cout << std::endl << "Hal Jordan's Hand: " << std::endl;
    halJ->printHand();
    Player* johnS = new Player(11, "John Stewart");
    extraTable->addFront(johnS);
    johnS->drawCard(new Card("Green", "3"));
    johnS->drawCard(new Card("Green", "7"));
    johnS->drawCard(new Card("Red", "5"));
    johnS->drawCard(new Card("Red", "2"));
    std::cout << std::endl << "John Stewart's Hand: " << std::endl;
    johnS->printHand();
    Player* guyG = new Player(12, "Guy Gardner");
    extraTable->addFront(guyG);
    guyG->drawCard(new Card("Green", "4"));
    guyG->drawCard(new Card("Green", "Reverse"));
    guyG->drawCard(new Card("Red", "4"));
    guyG->drawCard(new Card("Blue", "2"));
    std::cout << std::endl << "Guy Gardner's Hand: " << std::endl;
    guyG->printHand();
    Player* kyleR = new Player(13, "Kyle Rayner");
    extraTable->addFront(kyleR);
    kyleR->drawCard(new Card("Green", "9"));
    kyleR->drawCard(new Card("Red", "9"));
    kyleR->drawCard(new Card("Green", "4"));
    kyleR->drawCard(new Card("Blue", "6"));
    std::cout << std::endl << "Kyle Rayner's Hand: " << std::endl;
    kyleR->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Kyle Rayner" << std::endl;
    kyleR->printHand();
    Card* played0 = kyleR->playCard();
    if (played0 != nullptr) {
        std::cout << "Card played: " << *played0 << std::endl;
        delete played0;
    }
    kyleR->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Guy Gardner" << std::endl;
    guyG->printHand();
    Card* played1 = guyG->playCard();
    if (played1 != nullptr) {
        std::cout << "Card played: " << *played1 << std::endl;
        delete played1;
    }
    guyG->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: John Stewart" << std::endl;
    johnS->printHand();
    Card* played2 = johnS->playCard();
    if (played2 != nullptr) {
        std::cout << "Card played: " << *played2 << std::endl;
        delete played2;
    }
    johnS->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Hal Jordan" << std::endl;
    halJ->printHand();
    Card* played3 = halJ->playCard();
    if (played3 != nullptr) {
        std::cout << "Card played: " << *played3 << std::endl;
        delete played3;
    }
    halJ->printHand();

    std::cout << std::endl;
    std::cout << "Played Reverse!" << std::endl;
    extraTable->reverse();
    std::cout << std::endl;

    extraTable->print();
    std::cout << std::endl << "Turn: John Stewart" << std::endl;
    johnS->printHand();
    Card* played4 = johnS->playCard();
    if (played4 != nullptr) {
        std::cout << "Card played: " << *played4 << std::endl;
        delete played4;
    }
    johnS->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Guy Gardner" << std::endl;
    guyG->printHand();
    Card* played5 = guyG->playCard();
    if (played5 != nullptr) {
        std::cout << "Card played: " << *played5 << std::endl;
        delete played5;
    }
    guyG->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Kyle Rayner" << std::endl;
    kyleR->printHand();
    Card* played6 = kyleR->playCard();
    if (played6 != nullptr) {
        std::cout << "Card played: " << *played6 << std::endl;
        delete played6;
    }
    kyleR->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Hal Jordan" << std::endl;
    halJ->printHand();
    Card* played7 = halJ->playCard();
    if (played7 != nullptr) {
        std::cout << "Card played: " << *played7 << std::endl;
        delete played7;
    }
    halJ->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: John Stewart" << std::endl;
    johnS->printHand();
    Card* played8 = johnS->playCard();
    if (played8 != nullptr) {
        std::cout << "Card played: " << *played8 << std::endl;
        delete played8;
    }
    johnS->printHand();

    extraTable->print();
    std::cout << std::endl << "Turn: Guy Gardner" << std::endl;
    guyG->printHand();
    Card* played9 = guyG->playCard();
    if (played9 != nullptr) {
        std::cout << "Card played: " << *played9 << std::endl;
        delete played9;
    }
    guyG->printHand();

    std::cout << std::endl;
    std::cout << "Played Reverse!" << std::endl;
    extraTable->reverse();
    std::cout << std::endl;
    extraTable->print();

    return 0;
}
