#include "explorer.h"
#include <iostream>
#include "/public/colors.h"
using namespace std;

Explorer::Explorer(string n) : name(n), health(6) {
    for (int i = 0; i < 6; i++) hearts.push_back("💗");
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





void Explorer::showHealthHearts() const {
    for (int i = 0; i < health; i++) cout << "💗";
}




