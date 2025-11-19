#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "puzzles.h"
#include "/public/colors.h"
using namespace std;

void PuzzleGame::puzzles(int x){
	if(x == 1){
		cout << "Welcome to the puzzles";
		cout << "For the puzzles you have to answer the riddles correctly, if you do you get a secrets letter that will help you unlock the final game!!!\n";
		clearscreen();
		movecursor(25, 95);
		cout << "Puzzle 1: Guess the animal!! The alphabet goes from A to Z but I go from Z to A\n";
		string answer;
		getline(cin, answer);
		if(answer == "zebra"){
			cout << "Good job, Your first key is the letter " << RED << "E G\n";
			inventory.push_back("E G");
		} else{
			cout << "Unfortunately you got the question wrong!!\nBetter luck next time!!\n";
			return;
		}
		if(x == 2){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 2: I swing through trees, I hoot and chatter, my tail helps me climb, what am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "monkey"){
            cout << "Nice work! Your second key is the letter " << GREEN << "T U\n";
            inventory.push_back("T U");
        } else {
            cout << "Oops! That’s not quite right.\n";
            return;
        }
    }
    if(x == 3){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 3: I have stripes but I’m not a shirt, I roar but I’m not a lion. Who am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "tiger"){
            cout << "Well done! Your third key is the letter " << BLUE << "A M\n";
            inventory.push_back("A M");
        } else {
            cout << "Wrong answer! Try again next time.\n";
            return;
        }
    }
    if(x == 4){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 4: I slither silently, my hiss warns you, I might be venomous too. What am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "snake"){
            cout << "Correct! Your fourth key is the letter " << YELLOW << "E N\n";
            inventory.push_back("E N");
        } else {
            cout << "Not quite! Better luck next time.\n";
            return;
        }
    }
    if(x == 5){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 5: I’m big and gray, with ears that flap, I use my trunk to grab a snack. Who am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "elephant"){
            cout << "Great job! Your fifth key is the letter " << CYAN << "P L\n";
            inventory.push_back("P L");
        } else {
            cout << "Incorrect! Keep trying!\n";
            return;
        }
    }
    if(x == 6){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 6: I hang upside down and move real slow, in the jungle trees I go. What am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "sloth"){
            cout << "Awesome! Your sixth key is the letter " << MAGENTA << "I D\n";
            inventory.push_back("I D");
        } else {
            cout << "Nope! That’s not it.\n";
            return;
        }
    }
    if(x == 7){
        clearscreen();
        movecursor(25, 95);
        cout << "Puzzle 7: I croak and leap, I love the rain, my skin is smooth, I’m not plain. What am I?\n";
        string answer;
        getline(cin, answer);
        if(answer == "frog"){
            cout << "You nailed it! Your seventh key is the letter " << WHITE << "A R\n";
            inventory.push_back("A R");
        } else {
            cout << "That’s not the answer! Try again!\n";
            return;
        }
    }

}
}
void PuzzleGame::finalGate() const{
	cout << "The following letters are the the letters that you have collected throughout the game puzzles\n";
	for(int i = 0; i < inventory.size(); i++){
		cout << inventory.at(i) << " ";
	}
	cout << endl;
	cout << "Based on this letters can you guess the final phrase?(Write phrase in all caps)\n";
	string input;
	getline(cin, input);
	if(input == "GUARDIAN TEMPLE"){
		cout << "GOOOD JOB!! YOU GOT THE CODE RIGHT!!\nTHANK YOU FOR TUNING IN TO THE JUNGLE JOURNEY\n";
	} else{
		cout << "UNFORTUNATELY YOU DID NOT GET THE CODE RIGHT, MAYBE NEXT TIME\n";
		return;
	}
}

