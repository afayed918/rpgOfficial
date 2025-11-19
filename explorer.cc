#include "explorer.h"
#include <iostream>
#include "/public/colors.h"
using namespace std;

Explorer::Explorer(string n) : name(n), health(10) {
    for (int i = 0; i < 10; i++) hearts.push_back("💗");
}

void Explorer::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}

void Explorer::showHealth() const {
    setcolor(255, 0, 0);
    for (int i = 0; i < health; i++) cout << hearts[i];
    cout << RESET << endl;
}


bool Explorer::isDead() const {
    return (health <= 0);
}


void Explorer::showHealthHearts() const {
    for (int i = 0; i < health; i++) cout << "💗";
}




