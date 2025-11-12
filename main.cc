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
	const int ROWS = map;
	const int COLS = map.();
	int row = ROWS/2, col = COLS/2;
	string input;
	for (int i = 0; i < 255; i++) {
		clearscreen();
		setbgcolor(61, 94, 44);
		usleep(100'000);
		break;
	}
	movecursor(4, 40);
	setcolor(214, 214, 214);
	setbgcolor(86, 125, 8);
	string title = "JUNGLE JOURNEY";
	movecursor (4, 90);
	setcolor (214, 214, 214);
	setbgcolor (86, 125, 8);
	string title = "JUNGLE JOURNEY";// THis just makes typewriter effect
	for (char c : title) {
		cout << c << flush;
		usleep(150'000);
	}
	while(true){
		int c = toupper(quick_read());
        if (c == 'Q') break;
        if (c == 'W' or c == UP_ARROW) row--;
        if (c == 'S' or c == DOWN_ARROW) row++;
        if (c == 'A' or c == LEFT_ARROW) col--;
        if (c == 'D' or c == RIGHT_ARROW) col++;
		for(size_t i = 0; i < map.size(); i++);{
			for(size_t j = 0; i < map.at(0).size(); i++){
				if(map.at(i).at(j) == "thingy"){
					cout << "You just picked up thing\n";
					cout << "Welcome to the next level\n";
				}

			}
	}
	}
	cout << endl;
	cout << RESET;
	/*for (int i = 0; i < 255; i++) {
	   clearscreen();
	   setbgcolor(61,94,44);
	/*for (int i = 0; i < 255; i++) { // This is just something I grabbed from the
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
}

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
