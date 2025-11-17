#ifndef EXPLORER_H
#define EXPLORER_H
#include <string>
#include <vector>
using namespace std;

class Explorer {
private:
    string name;
    int health;
    vector<string> hearts;

public:
    Explorer(string n);
    void takeDamage(int dmg);
    void showHealth() const;
	void showHealthHearts() const;

};
#endif

