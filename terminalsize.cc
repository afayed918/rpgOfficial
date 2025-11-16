#include "/public/colors.h"
#include <utility>
using namespace std;

int main() {
	pair <int, int> p = get_terminal_size();


	cout << p.first << " " << p.second << endl;
}
