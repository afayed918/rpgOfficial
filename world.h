#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
using namespace std;

const int MAX_SIZE = 20;

void init_map(vector<string> &map);
void print_map(const vector<string> &map);
void save_map(const vector<string> &map, string file);
void load_map(vector<string> &map, string file);

#endif
