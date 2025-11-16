//Fill out this comment with your names and which bullet points you did
//Partners:Moyinoluwa Oyinleye,
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
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
	cout << "You fuhed up...\n";
	exit(0);
}
/*char get_world_location(size_t row, size_t col) {
	if (row >= world_map.size()) return ' ';
	bridges_project_1   if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void set_world_location(size_t row, size_t col, char c) {
	if (row >= world_map.size()) return;
	if (col >= world_map.at(row).size()) return;
	world_map.at(row).at(col) = c;
}

void print_world(size_t player_row, size_t player_col) {
	clearscreen();
	movecursor(0, 0);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << "💩";
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}*/

int main() {
	int map = 0;
	const int ROWS = map;
	const int COLS = map.();
	int row = ROWS / 2, col = COLS / 2;
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
	/*for (int i = 0; i < 255; i++) {
	   clearscreen();
	   setbgcolor(61,94,44);
	*for (int i = 0; i < 255; i++) { // This is just something I grabbed from the
	   clearscreen();				// bunny demo to test out, i will delete it later prob.
	   setbgcolor(61,94,44);
	   setcolor(i,0,0);
	    movecursor(i % 10,i % 30);

	   	usleep(100'000);
	}
	*/
	string usName;
	/*string wC = "WELCOME: " ;
	for (char c : wC ) {
	    cout << c << flush;
	    usleep(100'000);
	}
	*/
	movecursor(6, 33);
	string peaUN = "PLEASE ENTER A USERNAME: \n";
	for (char c : peaUN) {
		cout << c << flush;
		usleep(100'000);
	}
	getline(cin, usName);

	string wC = "WELCOME " + usName + "!\n";
	for (char c : wC) {
		cout << c << flush;
		usleep(100'000);
		movecursor(6, 83);
		string peaUN = "PLEASE ENTER A USERNAME: ";// THis just makes typewriter effect
		for (char c : peaUN) {
			cout << c << flush;
			usleep(100'000);
		}

		getline(cin, usName);

		movecursor(7, 88);
		string wC = "WELCOME " + usName + "!" ; // THis just makes typewriter effect
		for (char c : wC) {
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
	}
	set_raw_mode(true);
    show_cursor(false);
	while (true) {
        int c = toupper(quick_read());
        if (c == 'Q') break;
        if (c == 'W' || c == UP_ARROW) row--;
        if (c == 'S' || c == DOWN_ARROW) row++;
        if (c == 'A' || c == LEFT_ARROW) col--;
        if (c == 'D' || c == RIGHT_ARROW) col++;

        // Bounds check
        row = max(0, min(row, ROWS - 1));
        col = max(0, min(col, COLS - 1));

        char location = map.at(row).at(col);

        for (size_t i = 0; i < map.size(); i++) {
            for (size_t j = 0; j < map.at(0).size(); j++) {
                if (location == '?') {
                    cout << "Puzzle 1: What has keys but can't open doors?\n";
                    string answer;
                    getline(cin, answer);
                    if (answer == "keyboard") {
                        cout << "Correct! You solved Puzzle 1.\n";
                    } else {
                        die();
                    }
                }

                else if (location == '@') {
                    cout << "Puzzle 2: Solve this math: 12 + 8 * 2 = ?\n";
                    int response;
                    cin >> response;
                    if (response == 28) {
                        cout << "Nice! Puzzle 2 complete.\n";
                    } else {
                        die();
                    }
                }

                else if (location == '#') {
                    cout << "Puzzle 3: Enter the secret code (hint: it's 'JUNGLE'):\n";
                    string code;
                    getline(cin >> ws, code); // ws skips leading whitespace
                    if (code == "JUNGLE") {
                        cout << "You unlocked the final gate!\n";
                    } else {
                        die();
                    }
                }
            }
        }
    }

	int hpChoice = 0;
	if (hpChoice == 1) {
		int i = 0;
		for (i = 0; i < 101; i++) {
			clearscreen();
			setbgcolor(17, 71, 10);
			movecursor(25, 95);
			cout << i << "%" << endl;
			usleep(50'000);
		}
		// TODO: Link to world map or combat scene after loading bar
		//have to ask jacob about this because i wanna system("./combat") but he needs world map to appear first after loading screen **
	} else if (hpChoice == 2) {

		return 0;
	} else {
		return 0;
	} else if (hpChoice == 2) {
		return 0;
	} else {
		return 0;
	}
}
