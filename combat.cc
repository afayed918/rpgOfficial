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

// ======== SIMPLE GLOBAL HABIT TRACKING ====================================
// These track the player's general behavior across ALL encounters. //THIS IS AI
int gFightCount = 0;
int gHideCount = 0;
int gRunCount = 0;

// Record a habit (1=fight, 2=hide, 3=run)
void recordHabit(int choice){
    if(choice == 1) gFightCount++;
    if(choice == 2) gHideCount++;
    if(choice == 3) gRunCount++;
}

// If the player fights too often, beasts gain +1 damage.
int habitBonusDamage(){
    return (gFightCount >= 3) ? 1 : 0;
}

// If player hides too much, reduce hide success by 20%.
int habitHidePenalty(){
    return (gHideCount >= 3) ? 20 : 0;
}

// If player runs too much, reduce escape success by 20%.
int habitRunPenalty(){
    return (gRunCount >= 3) ? 20 : 0;
}





void gameOver() {
    clearscreen();
    setcolor(255,0,0);
    cout << "==========================================" << endl;
    cout << "                 GAME OVER                 " << endl;
    cout << "==========================================" << endl;
    cout << RESET;
    exit(0);
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
		explorer.takeDamage(1 + habitBonusDamage());
		if (explorer.isDead()) {
   	 	gameOver();
		}
		explorer.showHealth();
        
    }

    cout << endl;
}




void hide_from_tiger(Explorer &explorer) {
    clearscreen();
	movecursor(25, 135);
    cout << "You dive behind a thick bush...\n";
    usleep(2'200'000);

    int chance = rand() % 100; // 0–99

    int hideChance = 60 - habitHidePenalty();
		if(hideChance < 10) hideChance = 10;

		if(chance < hideChance){

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
		
		explorer.takeDamage(1 + habitBonusDamage());
		if (explorer.isDead()) {
    	gameOver();
		}

		movecursor(29, 135);
		explorer.showHealth();
        
		movecursor(30, 135);
		cout << "You scramble the heck outta there as fast as you can!!\n";
		usleep(1'200'000);

    }

    cout << endl;
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
    cout << "               #"; 

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

	void refreshBattle(Explorer &explorer, Beast &tiger){
        clearscreen();
        drawBattleScreen(explorer, tiger);
    }


bool enemyMove(){
	int roll = 2;//rand() % 4;
	if(roll) return true; //Hit explorer
	else return false; // Flee from explorer
}

	
void tigerFight(Explorer &explorer, Beast &tiger) {
    int row = 10;
    int col = 120;

    clearscreen();
    drawBattleScreen(explorer, tiger);
	srand(time(NULL));
	clearscreen();

	Explorer explorer("Explorer");
	Beast tiger("Bengal Tiger", 2);
	explorer.showHealth();


    movecursor(row++, col);
    cout << "The tiger snarls and prepares to strike..." << endl;

    movecursor(row++, col);
    cout << "Choose your action:" << endl;
    movecursor(row++, col);
    cout << "1) FIGHT" << endl;
    movecursor(row++, col);
    cout << "2) HIDE" << endl;
    movecursor(row++, col);
    cout << "3) RUN" << endl;
    movecursor(row++, col);
    cout << " ";

    int choice;
    cin >> choice;
	recordHabit(choice); // AI

    // fighttttt
    if (choice == 1) {
        clearscreen();
        row = 10; col = 120;
        drawBattleScreen(explorer, tiger);

        movecursor(row++, col);
        cout << "You swing your machete but take "
             << tiger.getStrength() << " damage!" << endl;

        explorer.takeDamage(tiger.getStrength()+ habitBonusDamage()); 
        if (explorer.isDead()) gameOver();
        movecursor(row++, col);
        explorer.showHealth();
        usleep(2'000'000);

        if (enemyMove()) {
            movecursor(row++, col);
            cout << "The tiger slashes again! +" << tiger.getStrength() << " dmg!" << endl;
            explorer.takeDamage(tiger.getStrength() + habitBonusDamage());
            if (explorer.isDead()) gameOver();

            movecursor(row++, col);
            explorer.showHealth();
            usleep(2'000'000);

            movecursor(row++, col);
            cout << "Choose:" << endl;
            movecursor(row++, col);
            cout << "1) RUN" << endl;
            movecursor(row++, col);
            cout << "2) CONTINUE FIGHT" << endl;
            movecursor(row++, col);
            cout << " ";
            int sec;
            cin >> sec;
            cout << tiger.getStrength() << " damage!" << endl;


            if (sec == 1) {
                clearscreen();
                row = 10;
                movecursor(row++, col);
                cout << "You escaped with "; explorer.showHealth(); cout << endl;
                return;
            }
            else {
                explorer.takeDamage(tiger.getStrength() + habitBonusDamage());
                if (explorer.isDead()) gameOver();

                clearscreen();
                row = 10;
                movecursor(row++, col);
                cout << "You manage to run after taking another hit!" << endl;
                movecursor(row++, col);
                cout << "Remaining hearts: "; explorer.showHealth();
                return;
            }
        } else {
            clearscreen();
            row = 10;
            movecursor(row++, col);
            cout << "You land a critical hit!" << endl;
            movecursor(row++, col);
            cout << "The tiger flees into the jungle..." << endl;
            return;
        }
    }

    // hiding
    if (choice == 2) {
        hide_from_tiger(explorer);
        return;
    }

    // running
    if (choice == 3) {
        run_from_tiger(explorer);
        return;
    }
}

    








void serpentFight(Explorer &explorer, Beast &snake) {
    int row = 10;
    int col = 120;

    clearscreen();
    movecursor(row++, col);
    cout << "A cold hiss crawls up your spine..." << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "The Elder Serpent coils before you!" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "You are dragged into battle instantly!" << endl;
    usleep(2'500'000);

    drawBattleScreen(explorer, snake);
    usleep(1'500'000);

    row = 20;
    movecursor(row++, col);
    cout << "You slash wildly and cut the serpent!" << endl;
    usleep(2'000'000);

    movecursor(row++, col);
    cout << "The serpent shrieks and bites you!" << endl;
    usleep(2'000'000);

    explorer.takeDamage(snake.getStrength() + habitBonusDamage());
    if (explorer.isDead()) gameOver();

    movecursor(row++, col);
    explorer.showHealth();
    usleep(2'000'000);

    clearscreen();
    row = 10;
    movecursor(row++, col);
    cout << "The Elder Serpent fades away..." << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "Sssseek myyy hinttt... a parttt of your keyyy" << endl;
    movecursor(row++, col);
    cout << "iss what I call... home..." << endl;
    usleep(4'000'000);
}



void gorillaFight(Explorer &explorer, Beast &gorilla) {
	int row = 10;
	int col = 120;


    clearscreen();
	movecursor(row++, col);
    cout << "You step into a quiet clearing..." << endl;
    usleep(2'500'000);
	movecursor(row++, col);
    cout << "A massive Silverback Gorilla watches you silently." << endl;
    usleep(2'500'000);
	movecursor(row++, col);
    cout << "He beats his chest once *BOOM* a thunderous warning." << endl;
    usleep(2'500'000);

    cout << endl;
	movecursor(row++, col);
    cout << "What will you do?" << endl;
    movecursor(row++, col);
	cout << "1) Stay calm" << endl;
    movecursor(row++, col);
	cout << "2) Offer respect" << endl;
    movecursor(row++, col);
	cout << "3) Threaten him" << endl;
	movecursor(row++, col);	

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
	cout << "";

    int choice;
    cin >> choice;

   // NON-HOSTILE OPTIONS

    if (choice == 1)  {
		recordHabit(2);
		int row = 10;
    	int col = 120;
        clearscreen();

		
		movecursor(row++, col);
        cout << "You remain perfectly still..." << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "The gorilla snorts and walks away peacefully." << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
		cout << "He throws up gang signs at you and then opens up a banana :O" << endl;
		usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "You avoided conflict." << endl;
        return;
    }

    if (choice == 2)  {
		recordHabit(2);
		int row = 10;
		int col = 120;
        clearscreen();
		movecursor(row++, col);
        cout << "You bow your head in respect..." << endl;
        usleep(2'500'000);
		
        movecursor(row++, col);
		cout << "The gorilla gently taps the ground twice." << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "You're a good boy *rubs you gently*" << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "He allows you to pass safely...2 Words he spells out with his hands." << endl;
        return;
    }

    
    // if u choose the hostile choice uh oh
    if (choice == 3) {
		recordHabit(1);
		int row = 10;
		int col = 120;
		
        clearscreen();
		movecursor(row++, col);
        cout << "You raise your weapon..." << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "The Silverback ROARS!" << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "The battle begins!" << endl;
        usleep(2'500'000);

        int gorillaHealth = 3;   // Gorilla must be hit 3 times to surrender
		int rageLevel = 1;

        while (gorillaHealth > 0) {
		int row = 15;
		int col = 120;

		clearscreen();
            drawBattleScreen(explorer, gorilla);
			
			movecursor(row++, col);
            cout << "What will you do?" << endl;
			movecursor(row++, col);
            cout << "1) FIGHT" << endl;
			movecursor(row++, col);
            cout << "2) RUN" << endl;
			movecursor(row++, col);
			cout << " ";

            int action;
            cin >> action;

            
            // PLAYER CHOOSES TO RUN
            
            if (action == 2) {
				recordHabit(3); // RUN
				int row = 10;
				int col = 120;
                clearscreen();

				movecursor(row++, col);
                cout << "You turn and RUN!" << endl;
                usleep(2'500'000);
				

				movecursor(row++, col);
                cout << "A banana falls out of your bag..." << endl;
                usleep(2'500'000);

                movecursor(row++, col);
				cout << "The gorilla stops chasing and picks it up curiously." << endl;
                usleep(2'500'000);

                
				movecursor(row++, col);
				cout << "You're safe... for now." << endl;
                return;
            }

  
            // PLAYER CHOOSES TO FIGHT
            clearscreen();
            drawBattleScreen(explorer, gorilla);

            // Gorilla attacks first
            int damage = gorilla.getStrength() * rageLevel;
			

			movecursor(row++, col);
            cout << "The gorilla's rage grows (Rage x" << rageLevel << ")!" << endl;
            usleep(2'500'000);

			movecursor(row++, col);
            cout << "The gorilla smashes you for " << damage << " damage!" << endl;

            explorer.takeDamage(damage + habitBonusDamage());
            if (explorer.isDead()) gameOver();
			
			movecursor(row++, col);
            explorer.showHealth();
            usleep(2'500'000);

            // Player hits back
            movecursor(row++, col);
			cout << "You strike the gorilla!" << endl;
            usleep(2'500'000);

            gorillaHealth--;

            if (gorillaHealth <= 0) break;
			
			rageLevel++; //when this goes up ur loowk fricked as hellll 
		    clearscreen();
			movecursor(row++, col);
            cout << "The gorilla becomes ANGRIER..." << endl;

			movecursor(row++, col);
            cout << "He picks you up by your foot and SMASHES you left and right!" << endl;
            usleep(2'500'000);
			

			movecursor(row++, col);
            cout << "He prepares for another attack..." << endl;
            usleep(2'500'000);
        }

       
        // GORILLA DEFEATED
        clearscreen();
		movecursor(row++, col);
        cout << "Your final strike forces the Silverback to retreat..." << endl;
        usleep(2'500'000);
		
		movecursor(row++, col);
        cout << "You survived Barely." << endl;
        usleep(2'500'000);
        return;
    }
}


void monkeyFight(Explorer &explorer, Beast &monkey) {

    int row = 10;
    int col = 120;

    clearscreen();
    movecursor(row++, col);
    cout << "You feel something watching you from above..." << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "A Riddletail Monkey drops from the trees!" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "It is I..Mr. Monkey, and I like annoying people" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "He throws a piece of fruit RIGHT at your head!" << endl;
    usleep(2'500'000);

    // Screen flash/annoying effect
    setbgcolor(200, 30, 30); // red annoying flash
    clearscreen();
    movecursor(row++, col);
    cout << "Your screen flashes red from the impact!!" << endl;
    usleep(2'500'000);

    setbgcolor(255, 255, 0); // yellow annoying flash
    clearscreen();
    movecursor(row, col);
    cout << "The monkey LAUGHS in your FACE!" << endl;
    usleep(2'500'000);

    setbgcolor(61, 94, 44); // reset jungle green
    cout << RESET;
    clearscreen();

    movecursor(row, col);
    cout << "You decide it's time to deal with this little mf-er" << endl;
    usleep(2'500'000);

    // Monkey must be hit twice to run away
    int monkeyHealth = 2;

    while (monkeyHealth > 0) {

        row = 15;
        col = 120;
        clearscreen();

        movecursor(row++, col);
        cout << "The monkey circles around and taunts you." << endl;
        usleep(2'500'000);

        // monkey attack
        movecursor(row++, col);
        cout << "The monkey throws MORE fruit at you!" << endl;
        usleep(2'500'000);

        explorer.takeDamage(monkey.getStrength() + + habitBonusDamage());
        if (explorer.isDead()){ gameOver();}

        movecursor(row++, col);
        explorer.showHealth();
        usleep(2'500'000);

        movecursor(row++, col);
        cout << "You swing at Mr. Monkey!" << endl;
        usleep(2'500'000);

        monkeyHealth--;

        if (monkeyHealth > 0) {
            movecursor(row++, col);
            cout << "He dodges and sticks his tongue out at you!" << endl;
            usleep(2'500'000);
        }
    }

    // Monkey defeated
    clearscreen();
    row = 10;
    col = 120;

    movecursor(row++, col);
    cout << "You swing again and the monkey gets scared off!" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "FINE GOSH! Just take your hint!!" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "Go where the stone eyes NEVER blink!!" << endl;
    usleep(3'000'000);

    cout << RESET;
}

void looraksFight(Explorer &explorer, Beast &loracks) {
	clearscreen();
	int row = 10;
	int col = 120;
			explorer.showHealth();
		}
	 
	
	movecursor(row++, col);
	cout << "The air thickens with glowing green mist..." << endl;
	usleep(2'500'000);

	movecursor(row++, col);
	cout << "A small moss-covered figure rises from the roots..." << endl;
	usleep(2'500'000);

	movecursor(row++, col);
	cout << "He adjusts his tiny mustache and squints at you." << endl;
	usleep(2'500'000);

	movecursor(row++, col);
	cout << "I am the Loraaks... speaker for the trees." << endl;
	usleep(2'500'000);

	cout << RESET;
	setbgcolor(61, 94, 44);
	clearscreen();


	row = 10;
	movecursor(row++, col);
	cout << "The Loraaks hums softly, waiting for your response..." << endl;
	usleep(2'500'000);
	
	movecursor(row++, col);
	cout << "1) Tell him you don't like trees" << endl;
	
	movecursor(row++, col);
	cout << "2) Tell him you're chill" << endl;
	
	movecursor(row++, col);
	cout << "";
	
	int choice;
	cin >> choice;
	
	//b ad choice
	if (choice == 1) {
	recordHabit(1);
    clearscreen();
    row = 10;

    movecursor(row++, col);
    cout << "You tell the Loraaks you don't like trees." << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "He stops humming..his eye twitches." << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "...You WHAT?!" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "Alright buddy....we're fighting." << endl;
    usleep(2'500'000);

	int loraaksHealth = 2;

    while (loraaksHealth > 0) {

        clearscreen();
        drawBattleScreen(explorer, loracks);

        int r = 15;

        movecursor(r++, col);
        cout << "1) FIGHT" << endl;
        movecursor(r++, col);
        cout << "2) RUN" << endl;
        movecursor(r++, col);
        cout << " ";

        int action;
        cin >> action;

        if (action == 2) {
			recordHabit(3);
            r = 10;
            clearscreen();

            movecursor(r++, col);
            cout << "Roots block your escape!" << endl;
            usleep(2'000'000);

            continue;
        }

        // Attack
        clearscreen();
        drawBattleScreen(explorer, loracks);

        int dmg = loracks.getStrength(); //trying this a different way for future ref
        r = 15; // too tired to write row ;(

        movecursor(r++, col);
        cout << "Roots whip around you!" << endl;

        explorer.takeDamage(dmg + habitBonusDamage());
        if (explorer.isDead()) gameOver();

        movecursor(r++, col);
        explorer.showHealth();
        usleep(2'000'000);

        movecursor(r++, col);
        cout << "You slash through the vines!" << endl;
        usleep(2'000'000);

        loraaksHealth--;
    }

    
    row = 10;
    clearscreen();

    movecursor(row++, col);
    cout << "The Loraaks proceeds to turn into a pile of leaves" << endl;
    usleep(2'000'000);
	}

	//chill ah answer
	if (choice == 2) {
    	clearscreen();
    	row = 10;

    	movecursor(row++, col);
    	cout << "You tell him you're chill." << endl;
    	usleep(2'500'000);

    	movecursor(row++, col);
    	cout << "He floats three inches off the ground." << endl;
    	usleep(2'500'000);

    	movecursor(row++, col);
    	cout << "Good looks dude" << endl;
    usleep(2'500'000);

    movecursor(row++, col);
    cout << "Peace........" << endl;
    usleep(2'500'000);

    return;
	}


}

bool startCombat(Explorer&explorer,
		Beast &tiger,
		Beast &snake,
		Beast &gorilla,
		Beast &monkey,
		Beast &loracks)
{ 
	srand(time(NULL)); //random time from 1970-2025
	int r = rand() % 5; // 0 to 4 index

	if(r ==0) {tigerFight(explorer, tiger);}
	else if (r == 1) {serpentFight(explorer, snake);}
	else if (r == 2) {gorillaFight(explorer, gorilla);}
	else if (r == 3) {monkeyFight(explorer, monkey);}
	else if (r == 4) looraksFight(explorer, loracks);

	return true; //return true cuz death is handled within the fight functions so we dont have to check 2x
}

int main() {
srand(time(NULL));
    clearscreen();

    Explorer explorer("Explorer");

    Beast tiger("Bengal Tiger", 2);
    Beast snake("Elder Serpent", 1);
    Beast gorilla("Silverback Gorilla", 3);
    Beast monkey("Mr. Monkey", 1);
    Beast loracks("Looraks", 2);

    explorer.showHealth();

    // Temp to test combat, change later
    looraksFight(explorer, loracks);

    return 0;
}



