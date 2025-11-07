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
using namespace std;


void die() {
	cout <<"You fuhed up...\n";
	exit(0);
}		

int main(){
	for (int i = 0; i < 255; i++) {
       clearscreen();
       setbgcolor(61,94,44); 
	   usleep(100'000);
	   break;
	}
	movecursor (4, 40);
	setcolor (214, 214, 214);
	setbgcolor (86, 125, 8);
	string title = "JUNGLE JOURNEY";
	for (char c : title) {
		cout << c << flush;
		usleep(150'000);
	}
	cout << endl;
	cout << RESET;
	/*for (int i = 0; i < 255; i++) {
       clearscreen();
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
	movecursor (6, 33);
	string peaUN = "PLEASE ENTER A USERNAME: \n";
	for (char c : peaUN) {
        cout << c << flush;
        usleep(100'000);
    }
	getline (cin, usName);
		
	string wC = "WELCOME " + usName + "!" ;
    for (char c : wC ) {
        cout << c << flush;
        usleep(100'000);
    }
}

