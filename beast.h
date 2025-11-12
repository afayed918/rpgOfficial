#ifndef BEAST_H
#define BEAST_H
#include <string>
using namespace std;

class Beast {
private:
    string species;
    int strength;

public:
    Beast(string s, int str);
    string getSpecies() const;
    int getStrength() const;
};
#endif

