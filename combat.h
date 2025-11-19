#ifndef COMBAT_H
#define COMBAT_H

#include "explorer.h"
#include "beast.h"

// FULL FIGHT FUNCTIONS (these already exist in combat.cc)
void tigerFight(Explorer &explorer, Beast &tiger);
void serpentFight(Explorer &explorer, Beast &snake);
void gorillaFight(Explorer &explorer, Beast &gorilla);
void monkeyFight(Explorer &explorer, Beast &monkey);
void looraksFight(Explorer &explorer, Beast &loracks);

// The combat router
bool startCombat(Explorer &explorer, int row, int col,
                 Beast &tiger,
				 Beast &snake,
                 Beast &gorilla,
				 Beast &monkey,
				 Beast &loracks);//still part of that ^^

#endif

