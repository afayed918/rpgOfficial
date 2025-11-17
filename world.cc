#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;

const int MAX_HEIGHT = 43;
const int MAX_WIDTH = 43;
const char VERT_WALL = '|';
const char HORI_WALL = '=';
const char EMPTY = '.';
const char PLAYER = 'P';
const char NPC = '%';
const char ANIMAL = 'X';
const char TREE = 'T';


void smooth_map(vector<string> &map) {
	vector<string> original = map;
	for (int i = 1; i < MAX_HEIGHT - 1; i++) {
		for (int j = 1; j < MAX_WIDTH - 1; j++) {
			int treeNeighbors = 0;
			for (int row = i - 1; row <= i + 1; row++) {
				for (int col = j - 1; col <= j + 1; col++) {
					if (row == i && col == j) continue;
					if (original.at(row).at(col) == 'T') treeNeighbors++;
				}
			}
			if (treeNeighbors >= 5) map.at(i).at(j) = 'T';
			else if (treeNeighbors <= 2) map.at(i).at(j) = '.';
		}
	}
}

void place_events(vector<string> &map) {
	for (int i = 1; i < MAX_HEIGHT - 1; i++) {
		for (int j = 1; j < MAX_WIDTH - 1; j++) {
			if (map.at(i).at(j) != '.') continue;
			if (rand() % 100 < 3) {
				char temp;
				if (rand() % 2 == 0) {
					temp = 'X';
				}
				else {
					temp = '%';
				}
				bool blocked = false;
				for (int row = i - 1; row <= i; row++) {
					for (int col = j - 1; col <= j + 1; col++) {
						char c = map.at(i).at(j);
						if (c == 'T' || c == 'X' || c == '%') {
							blocked = true;
							break;
						}
					}
					if (blocked) break;
				}
			if (!blocked) map.at(i).at(j) = temp;
			}
		}
	}
}

void init_map(vector<string> &map) {
	srand(7);
	for (int i = 0; i < MAX_WIDTH; i++) {
		for (int j = 0; j < MAX_HEIGHT; j++) {
			//Borders
			if (i == 0 || i == MAX_WIDTH - 1) {
				map.at(i).push_back(HORI_WALL);
			}
			else if (j == 0 || j == MAX_HEIGHT - 1) {
				map.at(i).push_back(VERT_WALL);
			}
			else {
				//Randomly generated objects on the inside
				char tile;
				int roll = rand() % 100;
				if (roll < 4) tile = NPC;
				else if (roll < 9) tile = ANIMAL;
				else if (roll < 65) tile = EMPTY;
				else tile = TREE;
				if (tile == '.' || tile == 'T') {
					if (j > 1 && (rand() % 100) < 40) tile = map.at(i).at(j - 1);
					if (i > 1 && (rand() % 100) < 40) tile = map.at(i - 1).at(j);
					if (i > 1 && j > 1 && (rand() % 100) < 20) tile = map.at(i - 1).at(j - 1);
				}
				if (tile == '&' || tile == 'X') {
					if (j > 0 && map.at(i).at(j - 1) == tile) tile = EMPTY;
					if (j > 0 && map.at(i - 1).at(j) == tile) tile = EMPTY;
					if (i > 0 && j > 0 && map.at(i - 1).at(j - 1) == tile) tile = EMPTY;
				}
				map.at(i).push_back(tile);
			}
		}
	}
	smooth_map(map);
	smooth_map(map);
	place_events(map);
}

void print_map(const vector<string> &map) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++){
			cout << map.at(i).at(j) << map.at(i).at(j);
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
