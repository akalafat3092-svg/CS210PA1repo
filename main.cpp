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

    return 0;
}
