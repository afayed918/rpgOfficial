#include "beast.h"

Beast::Beast(string s, int str) : species(s), strength(str) {}

string Beast::getSpecies() const {
	return species;
}

int Beast::getStrength() const { 
	return strength;
}




