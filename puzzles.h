#ifndef PUZZLES_H
#define PUZZLES_H
#include <vector>
#include <string>

using namespace std;
class PuzzleGame {
public:
    void puzzles(int x);
	void finalGate() const;
private:
    vector<string> inventory;
};

#endif

