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

void center(int spaces) {
    for (int i = 0; i < spaces; i++) cout << " ";
}




void run_from_tiger(Explorer &explorer) {
    clearscreen();
    cout << "You sprint through the dense jungle...\n";
    usleep(1'200'000);

    int chance = rand() % 100;  // escape chance

    if (chance < 60) {
        cout << "Your legs burn as you push harder...\n";
        usleep(1'200'000);
        cout << "The tiger slows down... you ESCAPED!\n";
    }
    else {
        cout << "You trip over a root!\n";
        usleep(1'200'000);
        cout << "The tiger catches up, prepare yourself!!!\n";
		cout << "You take 1 heart of damage.\n";
		explorer.takeDamage(1);
		explorer.showHealth();
        // Optional: You can return to combat() from here
    }

    cout << endl;
}




void hide_from_tiger(Explorer &explorer) {
    clearscreen();
	movecursor(25, 135);
    cout << "You dive behind a thick bush...\n";
    usleep(2'200'000);

    int chance = rand() % 100; // 0–99

    if (chance < 60) {
		movecursor(26, 135);
        cout << "The tiger sniffs the air.." << endl;;
        usleep(1'200'000);
		movecursor(27, 135);
        cout << "But it loses your scent. You’re safe...for now :O.\n";
    }
    else {
		movecursor(26, 135);
        cout << "The tiger hears rustling...\n";
        usleep(1'200'000);
		movecursor(27, 135);
        cout << "It spots you and starts charging again!\n";
		usleep(800'000);
		movecursor(28, 135);
		cout << "It lunges forward at you, CLAWS in your arm..OH NOOO\n";
		usleep(1'200'000);
		
		explorer.takeDamage(1);
		movecursor(29, 135);
		explorer.showHealth();
        
		movecursor(30, 135);
		cout << "You scramble the heck outta there as fast as you can!!\n";
		usleep(1'200'000);

    }

    cout << endl;
}

void refreshBattle(Explorer &explorer, Beast &tiger){
    	clearscreen();
    	drawBattleScreen(explorer, tiger);
	}



void drawBattleScreen(const Explorer &explorer, const Beast &tiger) {

    clearscreen();
    setcolor(255,255,255);

    int col = 120;   // <-- adjust this number to move everything left/right
    int row = 10;    // <-- adjust this number to move everything up/down 

    movecursor(row++, col);
    cout << "############################################### ";

    movecursor(row++, col);
    cout << "#               🌿 BATTLE MODE 🌿             #";

    movecursor(row++, col);
    cout << "#                                             #";

    movecursor(row++, col);
    cout << "#  Explorer           " << "Beast: " << tiger.getSpecies() << "     #";

    movecursor(row++, col);
    cout << "#  Hearts: ";
    explorer.showHealthHearts();
    cout << "                       #"; 

    movecursor(row++, col);
    cout << "#           (STR: " << tiger.getStrength() << ")                          #";

    movecursor(row++, col);
    cout << "#                                             #";

    movecursor(row++, col);
    cout << "#          What will you do?                  #";

    movecursor(row++, col);
    cout << "#                                             #";

    movecursor(row++, col);
    cout << "#   (1) FIGHT     (2) HIDE     (3) RUN        #";

    movecursor(row++, col);
    cout << "###############################################";

	
	movecursor(25, 142);
	cout << "";

    cout << RESET;
}



bool enemyMove(){
	int roll = 2;//rand() % 4;
	if(roll) return true; //Hit explorer
	else return false; // Flee from explorer
}

int main() {
	srand(time(NULL) + getpid());
	//srand(1);
	srand(time(NULL));	
	clearscreen();

	Explorer explorer("Explorer");
	Beast tiger("Bengal Tiger", 2);
	explorer.showHealth();




/*	for (int i = 0; i < 100; i++) {
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
	cout << "(3) RUN" << endl;
	movecursor (18, 90);
	cout << "";
*/
	bool eMove = enemyMove(); //declaring it local to use it in 2 if statements
	drawBattleScreen(explorer, tiger);
	int tigChoice = 0; //decl
	cin >> tigChoice;


	if (tigChoice == 1) {
		cout << "You swing your machete but take " << tiger.getStrength() << " damage!" << endl;
		
		explorer.takeDamage(tiger.getStrength());
		explorer.showHealth();
		
		if (eMove) {
			cout << "The tiger slashes at you again, you take " << tiger.getStrength() << " damage!" << endl;
			explorer.takeDamage(tiger.getStrength());
			explorer.showHealth();
			cout << "Make a choice: " << endl;
			cout << "1) RUN" << endl;
			cout << "2) CONTINUE FIGHT" << endl;
			int sec= 0;
			cin >> sec;
			if (sec== 1) {
				explorer.showHealth();
			cout << "You escaped with ";  explorer.showHealth(); cout << " hearts. Close Call DUDE..!" << endl;
			}
			else if (sec == 2) {
			explorer.takeDamage(tiger.getStrength());
			cout << "💔💔" << endl;
			cout << "You were defeated by the tiger ;( " << endl;
			cout<< "GAME OVER" << endl;
			return 0;
			}
			//continue this part in class
			//ask about move cursor to center screen function
			explorer.showHealth();
			
		}
		else {	
			cout << "You got a lucky hit, the tiger flees into the darkness. :O " << endl;
		}
	} else {
		cout << "You got a lucky hit, the tiger flees into the darkness. :O " << endl;
	}
} else if (tigChoice == 2) {
	cout << "You hiding dood" << endl;
} else if (tigChoice == 3) {
	cout << "You ran away" << endl;
}
	

	//__RUN____
	if (tigChoice == 2) {
		hide_from_tiger(explorer);
	}

	else if (tigChoice == 3) {
		run_from_tiger(explorer);
	}

}

