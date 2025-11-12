#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 20;
const char VERT_WALL = '|';
const char HORI_WALL = '_';
const char EMPTY = '.';
const char PLAYER = 'P';
const char NPC = 'N';
const char ANIMAL = 'A';
const char WATER = '~';
const char TREE = 'T';


void init_map(vector<string> &map) {
	srand(7);
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			//Borders
			if (i == 0 || i == MAX_SIZE - 1) {
				map.at(i).push_back(HORI_WALL);
			}
			else if (j == 0 || j == MAX_SIZE - 1) {
				map.at(i).push_back(VERT_WALL);
			}
			else {
				//Randomly generated objects on the inside
				int roll = rand() % 20;
				if (roll >= 0 & roll <= 3) map.at(i).push_back(NPC);
				if (roll == 4) map.at(i).push_back(WATER);
				if (roll >= 5 & roll <= 12) map.at(i).push_back(EMPTY);
				if (roll >= 13 & roll <= 15) map.at(i).push_back(ANIMAL);
				if (roll >= 16 & roll <= 19) map.at(i).push_back(TREE);
			}
		}
	}
}

void print_map(const vector<string> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++){
			cout << map.at(i).at(j);
		}
		cout << endl;
	}
}
void save_map(const vector<string> &map, string file) {
	ofstream outs(file);
	if (!outs) throw runtime_error("File does not exist");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++){
			outs << map.at(i).at(j);
		}
		outs << endl;
	}
}

void load_map(vector<string> &map, string file){
	ifstream ins(file);
	if (!ins) throw runtime_error("File does not exist");
	while (true) {
		string s;
		getline(ins, s, '\n');
		if (!ins) break;
		map.push_back(s);
	}

}

int main() {
	vector<string> map(MAX_SIZE, "");
	init_map(map);
	print_map(map);
	//save_map(map, "file.txt");
	//load_map(map, "file.txt");
}
