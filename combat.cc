#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include <cmath>
#include "/public/colors.h"
#include <unistd.h>
using namespace std;



int main() {



vector<string>health;
    health.push_back("💚");
    health.push_back("💚");
    health.push_back("💚");
    health.push_back("💚");
    health.push_back("💚");
    health.push_back("💚");
	
    cout << health.size() << endl; //Test case

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
	cout << " ";
	/*for (size_t ; size_t <= 6;) {
		movecursor (25, 90);
		cout << health.at(i);
		}

		cout << endl;
	//cin >>
	
*/
}
