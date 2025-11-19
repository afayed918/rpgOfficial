#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <unistd.h>
#include "/public/colors.h"
#include "/public/read.h"
#include "puzzles.h"
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
const char GATE = '#';
const int FPS = 60;
int puzzleCounter = 1;
PuzzleGame game;


void smooth_map(vector<string> &map) {
	vector<string> original = map;
	for (int i = 1; i < MAX_HEIGHT - 1; i++) {
		for (int j = 1; j < MAX_WIDTH - 1; j++) {
			if (map.at(i).at(j) != EMPTY && map.at(i).at(j) != TREE) continue;
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
					temp = ANIMAL;
				}
				else {
					temp = NPC;
				}
				bool blocked = false;
				for (int row = i - 1; row <= i; row++) {
					for (int col = j - 1; col <= j + 1; col++) {
						char c = map.at(row).at(col);
						if (c == TREE || c == ANIMAL || c == NPC) { 
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
	map.clear();
	map.resize(MAX_HEIGHT);
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			//Borders
			if (i == 0 || i == MAX_HEIGHT - 1) {
				map.at(i).push_back(HORI_WALL);
			}
			else if (j == 0 || j == MAX_WIDTH - 1) {
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
				if (tile == '%' || tile == 'X') {
					tile = EMPTY;
					//if (j > 0 && map.at(i).at(j - 1) == tile) tile = EMPTY;
					//if (j > 0 && map.at(i - 1).at(j) == tile) tile = EMPTY;
					//if (i > 0 && j > 0 && map.at(i - 1).at(j - 1) == tile) tile = EMPTY;
				}
				map.at(i).push_back(tile);
			}
		}
	}
}

void place_player(vector<string>& map, int& prow, int& pcol) {
	bool placed = false;
	for (int attempt = 0; attempt < 1000 && !placed; attempt++) {
		int r = rand() % (MAX_HEIGHT - 2) + 1;
		int c = rand() % (MAX_WIDTH - 2) + 1;

		if (map.at(r).at(c) == EMPTY) {
			prow = r;
			pcol = c;
			map.at(prow).at(pcol) = PLAYER;
			placed = true;
		}
	}
	if (!placed) {
		prow = MAX_HEIGHT / 2;
		pcol = MAX_WIDTH / 2;
		map.at(prow).at(pcol) = PLAYER;
	}
}

void print_map(const vector<string> &map) {
	clearscreen();
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++){
			if (map.at(i).at(j) == TREE) cout << BOLDGREEN << map.at(i).at(j) << map.at(i).at(j);
			else if (map.at(i).at(j) == HORI_WALL or map.at(i).at(j) == VERT_WALL) cout << MAGENTA << map.at(i).at(j) << map.at(i).at(j);
			else if (map.at(i).at(j) == ANIMAL) cout << RED << map.at(i).at(j) << map.at(i).at(j);
			else if (map.at(i).at(j) == NPC) cout << CYAN << map.at(i).at(j) << map.at(i).at(j);
			else if (map.at(i).at(j) == PLAYER ) cout << BOLDYELLOW  << map.at(i).at(j) << map.at(i).at(j);
			else cout << WHITE << map.at(i).at(j) << map.at(i).at(j);
		}
		if (i == map.size() - 1) cout << WHITE;
		cout << endl;
	}
}

bool try_move_player(vector<string> &map, int& prow, int& pcol, char input, PuzzleGame &game, int &puzzleCounter) {
	int nr = prow;
	int nc = pcol;
	if (input == 'w') nr--;
	else if (input == 's') nr++;
	else if (input == 'a') nc--;
	else if (input == 'd') nc++;
	else return false;
	char tile = map.at(nr).at(nc);
	if (tile == VERT_WALL || tile == HORI_WALL || tile == TREE) {
		return false;
	}
	if (tile == NPC) {
		set_raw_mode(false);
		clearscreen();
		game.puzzles(puzzleCounter);
		puzzleCounter++;
		cout << "\nPress Enter to continue..." << endl;
		string temp;
		getline(cin, temp);
		clearscreen();
		print_map(map);
		set_raw_mode(true);
	}
	map.at(prow).at(pcol) = '.';
	prow = nr;
	pcol = nc;
	map.at(prow).at(pcol) = PLAYER;
	return true;
}

void run_world_with_fps(vector<string>& map, int& prow, int& pcol) {
	const int FRAME_DELAY_US = 1'000'000 / FPS;
	int last_prow = -1;
	int last_pcol = -1;
	while (true) {
		int raw = quick_read();
		char key = 0;
		if (raw != -1) key = (char)raw;
		if (key) key = (char)tolower((unsigned char) key);
		if (key == 'q') break;
		bool moved = false;
		if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
			moved = try_move_player(map, prow, pcol, key, game, puzzleCounter);
		}
		if (moved || last_prow == -1) {
			print_map(map);
			last_prow = prow;
			last_pcol = pcol;
		}
		usleep(FRAME_DELAY_US);
	}
}

void run_world() {
	vector<string> map;
	int prow;
	int pcol;
	init_map(map);
	smooth_map(map);
	smooth_map(map);
	place_events(map);
	place_player(map, prow, pcol);
	print_map(map);
	set_raw_mode(true);
	run_world_with_fps(map, prow, pcol);
	set_raw_mode(false);
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
