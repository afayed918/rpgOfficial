#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include <cmath>
#include <unistd.h>
#include "/public/colors.h"
#include <unistd.h>
#include "explorer.h"
#include "beast.h"
using namespace std;


		//g++ combat.cc explorer.cc beast.cc -o combat -std=c++17


		//^^ use to compile


bool enemyMove(){
	int roll = 0;//rand() % 4;
	if(roll) return true; //Hit explorer
	else return false; // Flee from explorer
}

int main() {
	srand(1);
	//srand(time(NULL));	
	clearscreen();

	Explorer explorer("Explorer");
	Beast tiger("Bengal Tiger" , 2);
	explorer.showHealth();









	for (int i = 0; i < 100; i++) {
		clearscreen();
		movecursor(20, i % 100);
		setcolor(255, 119, 0);
		cout << "🐯" << endl;
		usleep(35'000);
	}

	explorer.showHealth();



	setcolor(255,52,0);
	setbgcolor(235,235,235);
	movecursor(10, 90);
	cout << "𝗔𝗛𝗛𝗛 𝗔 𝗧𝗜𝗚𝗘𝗥!!!" << endl;
	cout << RESET;
	movecursor(15, 90);
	cout << "(1) FIGHT" << endl;
	movecursor(16, 90);
	cout << "(2) HIDE" << endl;
	movecursor(17, 90);

	cout << "(3) RUN" << endl;
	movecursor (18, 90);
	cout << "";

	bool eMove = enemyMove(); //declaring it local to use it in 2 if statements
	int tigChoice = 0; //decl
	cin >> tigChoice;
	if (tigChoice == 1) {
		cout << "You swing your machete but take " << tiger.getStrength() << " damage!" << endl;
		explorer.takeDamage(tiger.getStrength());
		explorer.showHealth();
		if (eMove == true) {
			cout << "The tiger slashes at you again, you take " << tiger.getStrength() << " damage!" << endl;
			explorer.takeDamage(tiger.getStrength());
			explorer.showHealth();
			cout << "Make a choice: " << endl;
			cout << "1) RUN" << endl;
			cout << "2) CONTINUE FIGHT" << endl;
			int secTigChoice = 0;
			cin >> secTigChoice;
			if (secTigChoice == 1) {
				explorer.showHealth();
			cout << "You escaped with 2 hearts, close call.." << endl;
			}
			else if (secTigChoice == 2) {
			explorer.takeDamage(tiger.getStrength());
			cout << "💔💔" << endl;
			cout<< "YOU DIED XXX" << endl;
			cout<< "GAME OVER" << endl;
			}
			//continue this part in class
			//ask about move cursor to center screen function
			
		}
	}if (eMove == false) {
		cout << "You got a lucky hit, the tiger flees into the darkness. :O " << endl;
	}

	if (tigChoice == 2) {
		cout << "You hiding dood" << endl;
	}
	else if (tigChoice == 3) {
		cout << "You ran away" << endl;
	}

}
