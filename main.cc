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
using namespace std;


void die() {
	cout << "You fuhed up...\n";
	exit(0);
}
/char get_world_location(size_t row, size_t col) {
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
/
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
	
	movecursor (4, 90);
	setcolor (214, 214, 214);
	setbgcolor (86, 125, 8);
	string title = "JUNGLE JOURNEY";// THis just makes typewriter effect
	for (char c : title) {
		cout << c << flush;
		usleep(150'000);
	} 
	/
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
						cout 
						<< "Not all guardians mean you harm.\n"
						<< "Something here is watching you closely.\n"
						<< "Observing.\n"; 
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
						cout << "Another piece collected.\n"
							<< "The pattern should be getting clearer.\n"
							<< "Only one more stands between you and freedom.\n";
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
						cout << "That's the last fragment.\n"
							<< "Everything you need is now in your hands.\n"
							<< "All that remains is to put it together.\n";
					} else {
						die();
					}
				}
				cout << "The full message is almost complete.\n"
					<< "Take a moment before you continue, once it's revealed there is no going back.\n"
					<< "When you're ready, step forward to finish what you started.\n";

			}
		}
	}
*/	
	cout 
	<< "Everything you've gathered forms the message you came here to find.\n"
	<< "The pieces were never meant to stay seperated.\n"
	<< "Now that they’re together, the meaning is clear.\n"
    << "You’ve pushed through every obstacle placed in your way.\n"
    << "Nothing about this journey was straightforward.\n"
    << "But you kept going despite the confusion and setbacks.\n"
    << "Most people would’ve stopped long before reaching this point.\n"
    << "Finishing something difficult takes more than skill.\n"
    << "It takes actual commitment to see it through.\n"
    << "You’ve shown that in every step of this run.\n"
    << "As the last fragment locks into place, the message stabilizes.\n"
    << "There’s no more uncertainty in what comes next.\n"
    << "You’ve earned the right to see the final result.\n"
    << "Not because it was handed to you, but because you fought for it.\n"
    << "This place has tested everything from patience to focus.\n"
    << "And you pushed past all of it.\n"
    << "The path ahead is open now.\n"
    << "You’re free to move forward without anything holding you back.\n"
    << "Whatever comes after this point is completely up to you.\n"
    << "Take what you’ve learned here and use it.\n"
    << "Not everyone makes it to the end.\n"
    << "But you did, and that says enough on its own.\n";
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
			usleep(20'000);
		}
		cout << RESET;
		clearscreen();
		string begPuz = "Long ago, this land held a single truth...\n"
						"A message so important it was shattered into pieces\n"
						"and hidden across the realm.\n"
						"\n"
						"Each puzzle you face guards one fragment.\n"
						"Gather the letters.\n"
						"Reassemble the truth.\n"
						"\n"
						"Only then will you understand why you were brought here.";
		int row = 15;
		int col = 75;
		int startCol = col; // save the starting column

		for (char c : begPuz) {
    	// Handle newline manually
    	if (c == '\n') {
        row++;          // next line
        col = startCol; // reset to beginning of line
        continue;       // skip printing this char
    	}

    	movecursor(row, col);
    	cout << c << flush;

    	col++; // move to next horizontal position

    	usleep(75'000);
		}
		
		cout << endl;
		cout << "Every fragment you seek was hidden for a reason.\n"
			"Your journey will test more than your mind.\n"
			"It will test your resolve.\n"
			<< endl;
		int toContinue = 0;
		cout << RESET;
		while(toContinue != 1) {
		movecursor(30, 85);
		cout << "Press (1) to Continue: ";
		cin >> toContinue;
		if (toContinue == 1) { break; }
		}
			

		cout << RESET;
		clearscreen();
		vector<string> map(MAX_HEIGHT, "");
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
