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
#include "world.h"
#include "puzzles.h"
using namespace std;


void die() {
	cout << "You fuhed up...\n";
	exit(0);
	usleep(2'000'000);
}

int main() {
//	const int ROWS = map;
	//const int COLS = map.();
//	int row = ROWS / 2, col = COLS / 2;
	string input;
	for (int i = 0; i < 255; i++) {
		clearscreen();
		setbgcolor(61, 94, 44);
		usleep(100'000);
		break;
	}

	movecursor(4, 90);
	setcolor(214, 214, 214);
	setbgcolor(86, 125, 8);
	string title = "JUNGLE JOURNEY";// THis just makes typewriter effect
	for (char c : title) {
		cout << c << flush;
		usleep(150'000);
	}
			
		
	cout << endl;
	cout << RESET;
	string usName;
	movecursor(6, 83);
	string peaUN = "PLEASE ENTER A USERNAME: ";
	for (char c : peaUN) {
		cout << c << flush;
		usleep(100'000);
	}
	getline(cin, usName);
	movecursor(7, 88);
	string wC = "WELCOME " + usName + "!\n";
	for (char c : wC) {
		cout << c << flush;
		usleep(80'000);
	}
	set_raw_mode(true);
    show_cursor(false);
	 movecursor(10, 90);
    cout << "(1) Start Game" << endl;
    movecursor(11, 90);
    cout << "(2) Quit" << endl;
    movecursor (13, 90);
    cout << " ";

    int hpChoice = 0;
    cin >> hpChoice;

    if (hpChoice == 1) {
        int i = 0;
        for (i = 0; i < 101; i++) {
            clearscreen();
            setbgcolor(17, 71, 10);
            movecursor(25, 95);
            cout << i << "%" << endl;
            usleep(50'000);
        }

        cout << RESET;
        clearscreen();
        vector<string> map(MAX_SIZE, "");
        init_map(map);
        print_map(map);
    }
    else if (hpChoice == 2) {

        return 0;
    }
    else {
        return 0;
    }

        
 
}
