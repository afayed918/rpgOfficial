//Fill out this comment with your names and which bullet points you did
//Partners: Adam, Moyin, Nickolai, Jacob
//Bullet Points: 
//Extra Credit: 
//URL to cover art and music: 
#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include <cmath>
#include "/public/colors.h"
#include <unistd.h>
using namespace std;


void die() {
	cout <<"You fuhed up...\n";
	exit(0);
}		
bool hasItem(const vector<string>& inventory, const string& item) {
	return find(inventory.begin(), inventory.end(), item) != inventory.end();
}

bool trySolvePuzzle(const vector<string>& inventory) {
	if (hasItem(inventory, "mushroom") && hasItem(inventory, "leaf")) {
		cout << "You combined mushroom and leaf to create a forest key!\n";
		return true;
	}
	cout << "You don't have the right items yet.\n";
	return false;
}

int main(){
	vector<string> inventory;
	string input;
	for (int i = 0; i < 255; i++) {
		clearscreen();
		setbgcolor(61,94,44); 
		usleep(100'000);
		break;
	}
	movecursor (4, 90);
	setcolor (214, 214, 214);
	setbgcolor (86, 125, 8);
	string title = "JUNGLE JOURNEY";// THis just makes typewriter effect
	for (char c : title) {
		cout << c << flush;
		usleep(150'000);
	}
	cout << endl;
	cout << RESET;
	/*for (int i = 0; i < 255; i++) { // This is just something I grabbed from the
	  clearscreen();				// bunny demo to test out, i will delete it later prob.	
	  setbgcolor(61,94,44);
	  setcolor(i,0,0);
	  movecursor(i % 10,i % 30);

	  usleep(100'000);
	  }
	  */
	string usName;
	movecursor (6, 83);
	string peaUN = "PLEASE ENTER A USERNAME: ";// THis just makes typewriter effect
	for (char c : peaUN) {
		cout << c << flush;
		usleep(100'000);
	}

	getline (cin, usName);

	movecursor (7, 88);
	string wC = "WELCOME " + usName + "!" ; // THis just makes typewriter effect
	for (char c : wC ) {
		cout << c << flush;
		usleep(100'000);
	}

	//Opens the input file name "worldmapping.txt"
	ifstream inputFile("worldmapping.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		return 0;
	}
	string maplines;
	while (getline(inputFile, maplines)) {
		cout << maplines << endl; //prints every line of the worlmapping text file
	}

	int hpChoice = 0;
	if (hpChoice == 1) {
		int i = 0; 
		for (i = 0; i < 101; i++) {
			clearscreen();
			setbgcolor(17, 71, 10);
			movecursor (25, 95);
			cout << i << "%" <<endl;
			usleep(50'000);
		}
		clearscreen();
		movecursor (30, 100);
		cout << "_____________________________________________________________________________________________________________________________________________________________________________________________________";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "-                                                                                                                                                                                                   |";
		cout << "____________________________________________________________________________________________________________________________________________________________________________________________________|";
	}
	else if (hpChoice == 2) {

		return 0;	
	}
	else {
		return 0;
	}
}
