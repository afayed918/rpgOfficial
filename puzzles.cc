#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "puzzles.h"
#include "/public/colors.h"
#include "world.h"
using namespace std;

void PuzzleGame::puzzles(int x){
	if(x == 1){
		cout << "Welcome to the puzzles";
		cout << "For the puzzles you have to answer the riddles correctly, if you do you get a secrets letter that will help you unlock the final game!!!\n";
		clearscreen();
		movecursor(15, 50);
		cout << "Puzzle 1: Guess the animal!! The alphabet goes from A to Z but I go from Z to A (answer in all lowercase)\n";
		string answer;
		getline(cin, answer);
		if(answer == "zebra"){
			cout << "Good job, Your first key is the letters " << RED << "E G\n";
			inventory.push_back("E G");
		} else{
			cout << "Unfortunately you got the question wrong!!\nBetter luck next time!!\n";
			return;
		}
	}
		if(x == 2){//This code and the rest of the code below, are written with the use of AI. I provided AI with the example abve and it wrote the rest of the code for me
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 2: I swing through trees, I hoot and chatter, my tail helps me climb, what am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "monkey"){
            cout << "Nice work! Your second key is the letters " << GREEN << "T U\n";
            inventory.push_back("T U");
        } else {
            cout << "Oops! That’s not quite right.\n";
            return;
        }
    }
    if(x == 3){
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 3: I have stripes but I’m not a shirt, I roar but I’m not a lion. Who am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "tiger"){
            cout << "Well done! Your third key is the letters " << BLUE << "A M\n";
            inventory.push_back("A M");
        } else {
            cout << "Wrong answer! Try again next time.\n";
            return;
        }
    }
    if(x == 4){
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 4: I slither silently, my hiss warns you, I might be venomous too. What am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "snake"){
            cout << "Correct! Your fourth key is the letters " << YELLOW << "E N\n";
            inventory.push_back("E N");
        } else {
            cout << "Not quite! Better luck next time.\n";
            return;
        }
    }
    if(x == 5){
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 5: I’m big and gray, with ears that flap, I use my trunk to grab a snack. Who am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "elephant"){
            cout << "Great job! Your fifth key is the letters " << CYAN << "P L\n";
            inventory.push_back("P L");
        } else {
            cout << "Incorrect! Keep trying!\n";
            return;
        }
    }
    if(x == 6){
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 6: I hang upside down and move real slow, in the jungle trees I go. What am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "sloth"){
            cout << "Awesome! Your sixth key is the letters " << MAGENTA << "I D\n";
            inventory.push_back("I D");
        } else {
            cout << "Nope! That’s not it.\n";
            return;
        }
    }
    if(x == 7){
        clearscreen();
        movecursor(15, 50);
        cout << "Puzzle 7: I croak and leap, I love the rain, my skin is smooth, I’m not plain. What am I?(answer in lowercase)\n";
        string answer;
        getline(cin, answer);
        if(answer == "frog"){
            cout << "You nailed it! Your seventh key is the letters " << WHITE << "A R\n";
            inventory.push_back("A R");
        } else {
            cout << "That’s not the answer! Try again!\n";
            return;
        }
    }

}

void PuzzleGame::finalGate() const{
	clearscreen();
	movecursor(15, 50);
	cout << "The following letters are the the letters that you have collected throughout the game puzzles\n";
	for(int i = 0; i < inventory.size(); i++){
		cout << inventory.at(i) << " ";
	}
	cout << endl;
	cout << "Based on this letters can you guess the final phrase?(Write phrase in all caps)\n";
	string input;
	getline(cin, input);
	if(input == "GUARDIAN TEMPLE"){
		clearscreen();//This code and the rest of the code is coded with AI use
movecursor(10, 50);
cout << CYAN << "GOOOD JOB!! YOU GOT THE CODE RIGHT!!\n";
usleep(500'000);

clearscreen();
movecursor(15, 50);
cout << MAGENTA << "THANK YOU FOR TUNING IN TO THE JUNGLE JOURNEY\n";
usleep(500'000);

movecursor(17, 50);
cout << YELLOW << "The final door creaks open...\n";
usleep(500'000);

movecursor(18, 50);
cout << GREEN << "Sunlight floods the ancient chamber, revealing a mural of your journey.\n";
usleep(500'000);

movecursor(19, 50);
cout << CYAN << "\"You have proven your wisdom, courage, and heart,\" a voice whispers.\n";
usleep(500'000);

movecursor(20, 50);
cout << BLUE << "The fragments you gathered shimmer and rise, forming the sacred phrase:\n";
usleep(500'000);

movecursor(21, 50);
cout << GREEN << "\"GUARDIAN TEMPLE\"\n";
usleep(500'000);

movecursor(23, 50);
cout << RESET << "You feel the jungle breathe around you — no longer a stranger, but its chosen protector.\n";
usleep(500'000);

movecursor(25, 50);
cout << "As the vines part and the path clears, you step forward into legend.\n";
usleep(500'000);

movecursor(27, 50);
cout << MAGENTA << "This is not the end...\n";
usleep(500'000);

movecursor(28, 50);
cout << "It is the beginning of your legacy.\n";
usleep(500'000);

movecursor(30, 50);
cout << GREEN << "Thanks for playing!! May your next journey be just as wild.\n";
usleep(500'000);

movecursor(32, 50);
cout << RESET << "Press any key to exit...\n";
cin.ignore();
cin.get();
	} else{
    clearscreen();
    movecursor(10, 50);
    cout << RED << "UNFORTUNATELY YOU DID NOT GET THE CODE RIGHT...\n";
    usleep(500'000);

    movecursor(12, 50);
    cout << YELLOW << "The ancient stones remain silent.\n";
    usleep(500'000);

    movecursor(13, 50);
    cout << "The jungle watches, but does not speak.\n";
    usleep(500'000);

    movecursor(15, 50);
    cout << MAGENTA << "You were close, but the truth remains hidden.\n";
    usleep(500'000);

    movecursor(17, 50);
    cout << CYAN << "Perhaps the jungle will call you again one day...\n";
    usleep(500'000);

    movecursor(19, 50);
    cout << RESET << "Thank you for playing Jungle Journey.\n";
    usleep(500'000);

    movecursor(21, 50);
    cout << "Press any key to exit...\n";
    cin.ignore();
    cin.get();
    return;
}
	
}

