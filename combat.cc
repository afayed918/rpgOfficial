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



int main() {
	srand(time(NULL) + getpid());
	clearscreen();

	Explorer explorer("Explorer");
	Beast tiger("Bengal Tiger", 2);
	explorer.showHealth();









	for (int i = 0; i < 100; i++) {
		clearscreen();
		movecursor(20, i % 100);
		setcolor(255, 119, 0);
		cout << "🐯" << endl;
		usleep(35'000);
	}




	setcolor(255, 52, 0);
	setbgcolor(235, 235, 235);
	movecursor(10, 90);
	cout << "𝗔𝗛𝗛𝗛 𝗔 𝗧𝗜𝗚𝗘𝗥!!!" << endl;
	cout << RESET;
	movecursor(15, 90);
	cout << "(1) FIGHT" << endl;
	movecursor(16, 90);
	cout << "(2) HIDE" << endl;
	movecursor(17, 90);
	cout << "(3) RUN" << endl;
	movecursor(18, 90);
	cout << "";


	int tigChoice = 0; //decl
	cin >> tigChoice;
	if (tigChoice == 1) {
		cout << "You swing your machete but take " << tiger.getStrength() << " damage!" << endl;
		explorer.takeDamage(tiger.getStrength());
		explorer.showHealth();

		if (rand() % 2 == 0) {
			cout << "The tiger slashes at you again, you take " << tiger.getStrength() << " damage!" << endl;
			explorer.takeDamage(tiger.getStrength());
			cout << "Make a choice: " << endl;
			cout << "1) RUN" << endl;
			cout << "2) CONTINUE FIGHT" << endl;
			cin >> secTigChoice;
			//continue this part in class
			//ask about move cursor to center screen function
			explorer.showHealth();
		}
	} else {
		cout << "You got a lucky hit, the tiger flees into the darkness. :O " << endl;
	}
} else if (tigChoice == 2) {
	cout << "You hiding dood" << endl;
} else if (tigChoice == 3) {
	cout << "You ran away" << endl;
}

}
