#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
using namespace std;

//const int MAX_WIDTH = 43;
//const int MAX_HEIGHT = 43;

void init_map(vector<string> &map);
void smooth_map(vector<string> &map);
void place_events(vector<string> &map);
void place_player(vector<string> &map, int& prow, int& pcol);
bool try_move_player(vector<string>& map, int& prow, int& pcol, char input);
void print_map(const vector<string> &map);
void run_world();
void save_map(const vector<string> &map, string file);
void load_map(vector<string> &map, string file);

#endif
