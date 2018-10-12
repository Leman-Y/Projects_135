// Author: Marin Pavlinov Marinov
// Course: Csci-135
// Instructor: Genady Maryashi
// Assignment: project 3
#include "bot.h"
#include <cstdlib>
#include <iostream>
using namespace std;
<<<<<<< HEAD

const int MAX_ROBOT_NUM = 50;
int NUM;              // to remember number or robots
int ROWS, COLS;       // map dimensions
bool working = false; // to input
bool broken = true;
// array to store robot id's and determine whether they are working or not
bool robot_status[50];
// global variable to make the robots cycle up,down left or right instead of moving chaotically
bool cycle = false;
=======
const int MAX_ROBOT_NUM = 50;
int NUM;              // to remember number or robots
int ROWS, COLS;       // map dimensions
bool working = false; // to determine whether a robot can fine or broken down
bool broken = true;
// array to store robot id's and determine whether they are working or not
bool robot_status[50];
// global variable to make the robots cycle up,down left or right(depending on ROWS AND COLS)
// instead of moving chaotically
bool cycle = false;
// to notify if chance for malfunction is too high
bool danger = false;
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr, Area& area, ostream& log) {
	NUM = num; // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
<<<<<<< HEAD
=======
	// chance for malfunction is over 40% take extra care to repair the robots
	if (mpr >= 0.4) {
		danger = true;
	}
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
	for (int i = 0; i < 50; i++) {
		// make all robots working at the start
		robot_status[i] = working;
	}
	log << "Start!" << endl;
}
<<<<<<< HEAD
=======
///////function that checks to see if a robot is next to a robot and returns which side the robot is
///on
string botNextToBot(int id, int id_2, Loc loc, Area& area) {
	if (id_2 != id) {
		// notify whether the robot next to the other robot is either up,down,left, or right
		if (area.locate(id_2).r == area.locate(id).r + 1
		    && area.locate(id_2).c == area.locate(id).c) {
			return "BotUP";
		}
		if (area.locate(id_2).r == area.locate(id).r - 1
		    && area.locate(id_2).c == area.locate(id).c) {
			return "BotDOWN";
		}
		if (area.locate(id_2).r == area.locate(id).r
		    && area.locate(id_2).c == area.locate(id).c + 1) {
			return "BotLEFT";
		}
		if (area.locate(id_2).r == area.locate(id).r
		    && area.locate(id_2).c == area.locate(id).c - 1) {
			return "BotRIGHT";
		}
	}
	return "NONE";
}
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
// finds the broken robots row and column coardinates and then stores them
Loc findBrokenRobot(Loc loc, Area& area) {
	Loc def;
	for (int i = 0; i < NUM; i++) {
<<<<<<< HEAD
=======
		// finds the robot thats broken
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
		if (robot_status[i] == broken) {
			// return the coardinates
			def.r = area.locate(i).r;
			def.c = area.locate(i).c;
			return def;
		}
	}
	// if no broken robot is found then it returns non existant coardinates
	def.r = -1;
	def.c = -1;
	return def;
}
<<<<<<< HEAD
// compares Locs coardinates
bool locEquals(Loc thisL, Loc otherL) {
	if (thisL.r == otherL.r && thisL.c == otherL.c) {
		return true;
	}
	return false;
}
// finds the  debris that is d units away,in a circle
=======
// finds the  debris that is d units away,in a circle returns a string that tells the user which
// side the debris was found
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
string DebrisIsNear(int d, Loc loc, Area& area) {
	int row = loc.r;
	int col = loc.c;
<<<<<<< HEAD
=======
	// if there is a debri either horizontally or vertically, go straight to it
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
	if (area.inspect(row, col + d) == DEBRIS) {
		return "RIGHT";
	}
	if (area.inspect(row + d, col) == DEBRIS) {
		return "DOWN";
	}
	if (area.inspect(row - d, col) == DEBRIS) {
		return "UP";
	}
	if (area.inspect(row, col - d) == DEBRIS) {
		return "LEFT";
	}
	// one coardinate up,down,left, or right and d units away
<<<<<<< HEAD
	if (area.inspect(row + 1, col + d) == DEBRIS || area.inspect(row + 1, col - d) == DEBRIS)
=======
	if (area.inspect(row + 1, col + d) == DEBRIS || area.inspect(row + 1, col - d) == DEBRIS)
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
	{
		return "ONEDOWN";
	}
	if (area.inspect(row + d, col + 1) == DEBRIS || area.inspect(row - d, col + 1) == DEBRIS) {
		return "ONERIGHT";
	}
	if (area.inspect(row - 1, col + d) == DEBRIS || area.inspect(row - 1, col - d) == DEBRIS) {
		return "ONEUP";
	}
	if (area.inspect(row + d, col - 1) == DEBRIS || area.inspect(row - d, col - 1) == DEBRIS) {
		return "ONELEFT";
	}
	return "NOTHING";
}
<<<<<<< HEAD
=======



>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area& area, ostream& log) {
	int row = loc.r; // current row and column
	int col = loc.c;
<<<<<<< HEAD
	if (area.inspect(row, col) == DEBRIS) {
		return COLLECT;
	}
	// 		//Fix a robot if it breaks down
	Loc broken = findBrokenRobot(loc, area);
	if (loc.r == broken.r - 1 && loc.c == broken.c) {
		return REPAIR_DOWN;
	}
	if (loc.r == broken.r + 1 && loc.c == broken.c) {
		return REPAIR_UP;
	}
	if (loc.r == broken.r && loc.c == broken.c - 1) {
		return REPAIR_RIGHT;
	}
	if (loc.r == broken.r && loc.c == broken.c + 1) {
		return REPAIR_LEFT;
	}
	// inspect area around the robot, find a Debris that is near and go towards it
	// this matches the brute force but can be improved
	for (int i = 0; i < 40; i++) {
		if (DebrisIsNear(i, loc, area) == "RIGHT") {
			return RIGHT;
		}
		if (DebrisIsNear(i, loc, area) == "DOWN") {
			return DOWN;
		}
		if (DebrisIsNear(i, loc, area) == "UP") {
			return UP;
		}
		if (DebrisIsNear(i, loc, area) == "LEFT") {
			return LEFT;
		}
		if (DebrisIsNear(i, loc, area) == "ONEDOWN") {
			return DOWN;
		}
		if (DebrisIsNear(i, loc, area) == "ONEUP") {
			return UP;
		}
		if (DebrisIsNear(i, loc, area) == "ONELEFT") {
			return LEFT;
		}
		if (DebrisIsNear(i, loc, area) == "ONERIGHT") {
			return RIGHT;
		}
	}
	// When the above conditions are not satisfied...
	// robot will move LEFT or RIGHT if there are more rows than columns
	if (ROWS >= COLS) {
		if (cycle == false) {
			if (col == 0) {
				cycle = true;
			}
			return LEFT;
		}
		if (cycle == true) {
=======
	if (danger == false) {
		// prioritize collecting debris over going to broken robots
		if (area.inspect(row, col) == DEBRIS) {
			return COLLECT;
		}
	}
	Loc broke = findBrokenRobot(loc, area);
	// make sure there is more than one robot and
	if (NUM > 1) {
		// if the robot next to another robot is broken, repair it
		for (int id_2 = 0; id_2 < 50; id_2++) {
			if (botNextToBot(id, id_2, loc, area) == "BotUP") {
				// check for malfunction
				if (robot_status[id_2] == broken) {
					// always prioritize repairing(if needed) before separating
					// make it known to the array that the robot is now working
					robot_status[id_2] = working;
					return REPAIR_DOWN;
				}
			}
			if (botNextToBot(id, id_2, loc, area) == "BotDOWN") {
				if (robot_status[id_2] == broken) {
					robot_status[id_2] = working;
					return REPAIR_UP;
				}
			}
			if (botNextToBot(id, id_2, loc, area) == "BotLEFT") {
				if (robot_status[id_2] == broken) {
					robot_status[id_2] = working;
					return REPAIR_RIGHT;
				}
			}
			if (botNextToBot(id, id_2, loc, area) == "BotRIGHT") {
				if (robot_status[id_2] == broken) {
					robot_status[id_2] = working;
					return REPAIR_LEFT;
				}
			}
		}
	}
	// move towards damaged robots
	if (NUM > 1) {
		for (int f = 2; f < 40; f++) {
			if ((loc.r == broke.r - f && loc.c == broke.c) && (broke.r != -1 && broke.c != -1)) {
				return DOWN;
			}
			if (loc.r == broke.r + f && loc.c == broke.c && (broke.r != -1 && broke.c != -1)) {
				return UP;
			}
			if (loc.r == broke.r && loc.c == broke.c - f && (broke.r != -1 && broke.c != -1)) {
				return RIGHT;
			}
			if (loc.r == broke.r && loc.c == broke.c + f && (broke.r != -1 && broke.c != -1)) {
				return LEFT;
			}
			// one row/column
			if (loc.r == broke.r + 1 && (loc.c == broke.c + f || loc.c == broke.c - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return UP;
			}
			if (loc.r == broke.r - 1 && (loc.c == broke.c + f || loc.c == broke.c - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return DOWN;
			}
			if (loc.c == broke.c + 1 && (loc.r == broke.r + f || loc.r == broke.r - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return LEFT;
			}
			if (loc.c == broke.c - 1 && (loc.r == broke.r + f || loc.r == broke.r - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return RIGHT;
			}
			// two row column
			if (loc.r == broke.r + 2 && (loc.c == broke.c + f || loc.c == broke.c - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return UP;
			}
			if (loc.r == broke.r - 2 && (loc.c == broke.c + f || loc.c == broke.c - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return DOWN;
			}
			if (loc.c == broke.c + 2 && (loc.r == broke.r + f || loc.r == broke.r - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return LEFT;
			}
			if (loc.c == broke.c - 2 && (loc.r == broke.r + f || loc.r == broke.r - f)
			    && (broke.r != -1 && broke.c != -1)) {
				return RIGHT;
			}
			if (danger == true) {
				for (int d = 3; d < 40; d++) {
					if (loc.r == broke.r + d && (loc.c == broke.c + f || loc.c == broke.c - f)
					    && (broke.r != -1 && broke.c != -1)) {
						return UP;
					}
					if (loc.r == broke.r - d && (loc.c == broke.c + f || loc.c == broke.c - f)
					    && (broke.r != -1 && broke.c != -1)) {
						return DOWN;
					}
					if (loc.c == broke.c + d && (loc.r == broke.r + f || loc.r == broke.r - f)
					    && (broke.r != -1 && broke.c != -1)) {
						return LEFT;
					}
					if (loc.c == broke.c - d && (loc.r == broke.r + f || loc.r == broke.r - f)
					    && (broke.r != -1 && broke.c != -1)) {
						return RIGHT;
					}
				}
			}
		}
	}
	// this executes only after mpr is 40% or greater
	if (danger == true) {
		// collect debris only after  robots are fixed
		if (area.inspect(row, col) == DEBRIS) {
			return COLLECT;
		}
	}
	////only execute this if there is more than one robot
	if (NUM > 1) {
		// if two robots are clashed together, tell them to move spread apart
		for (int id_2 = 0; id_2 < 50; id_2++) {
			if (botNextToBot(id, id_2, loc, area) == "BotUP") {
				// if robot is next to robot, try to find a different debris to go to
				for (int i = 0; i < 40; i++) {
					if (DebrisIsNear(i, loc, area) == "LEFT") {
						return LEFT;
					}
					if (DebrisIsNear(i, loc, area) == "RIGHT") {
						return RIGHT;
					}
					if (DebrisIsNear(i, loc, area) == "ONEUP") {
						return UP;
					}
					if (DebrisIsNear(i, loc, area) == "ONELEFT") {
						return LEFT;
					}
					if (DebrisIsNear(i, loc, area) == "ONERIGHT") {
						return RIGHT;
					}
					if (DebrisIsNear(i, loc, area) == "UP") {
						return UP;
					}
				}
			}
			////////////////////////////////////////////////////////
			if (botNextToBot(id, id_2, loc, area) == "BotDOWN") {
				// always prioritize repairing(if needed) before separating
				for (int i = 0; i < 40; i++) {
					if (DebrisIsNear(i, loc, area) == "LEFT") {
						return LEFT;
					}
					if (DebrisIsNear(i, loc, area) == "RIGHT") {
						return RIGHT;
					}
					if (DebrisIsNear(i, loc, area) == "ONEDOWN") {
						return DOWN;
					}
					if (DebrisIsNear(i, loc, area) == "ONELEFT") {
						return LEFT;
					}
					if (DebrisIsNear(i, loc, area) == "ONERIGHT") {
						return RIGHT;
					}
					if (DebrisIsNear(i, loc, area) == "DOWN") {
						return DOWN;
					}
				}
			}
			////////////////////////////////////////////////////
			if (botNextToBot(id, id_2, loc, area) == "BotLEFT") {
				for (int i = 0; i < 40; i++) {
					if (DebrisIsNear(i, loc, area) == "DOWN") {
						return DOWN;
					}
					if (DebrisIsNear(i, loc, area) == "UP") {
						return UP;
					}
					if (DebrisIsNear(i, loc, area) == "ONEDOWN") {
						return DOWN;
					}
					if (DebrisIsNear(i, loc, area) == "ONEUP") {
						return UP;
					}
					if (DebrisIsNear(i, loc, area) == "ONELEFT") {
						return LEFT;
					}
					if (DebrisIsNear(i, loc, area) == "LEFT") {
						return LEFT;
					}
				}
			}
			//////////////////////////////////////////////////////
			if (botNextToBot(id, id_2, loc, area) == "BotRIGHT") {
				for (int i = 0; i < 40; i++) {
					if (DebrisIsNear(i, loc, area) == "DOWN") {
						return DOWN;
					}
					if (DebrisIsNear(i, loc, area) == "UP") {
						return UP;
					}
					if (DebrisIsNear(i, loc, area) == "ONEDOWN") {
						return DOWN;
					}
					if (DebrisIsNear(i, loc, area) == "ONEUP") {
						return UP;
					}
					if (DebrisIsNear(i, loc, area) == "ONERIGHT") {
						return RIGHT;
					}
					if (DebrisIsNear(i, loc, area) == "RIGHT") {
						return RIGHT;
					}
				}
			}
		}
	}
	// inspect area around the robot, find a Debris that is near and go towards it
	// else move either up or down, left or right based on whether ROWS or COLS are smaller
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			if (area.inspect(row + i, col) == DEBRIS) {
				return DOWN;
			}
			if (area.inspect(row - i, col) == DEBRIS) {
				return UP;
			}
			if (area.inspect(row, col + i) == DEBRIS) {
				return RIGHT;
			}
			if (area.inspect(row, col - i) == DEBRIS) {
				return LEFT;
			}
			if (area.inspect(row + i, col) == DEBRIS) {
				return DOWN;
			}
			if (area.inspect(row + i, col + j) == DEBRIS
			    || area.inspect(row + i, col - j) == DEBRIS) {
				return DOWN;
			}
			if (area.inspect(row - i, col + j) == DEBRIS
			    || area.inspect(row - i, col - j) == DEBRIS) {
				return UP;
			}
			if (area.inspect(row + i, col + j) == DEBRIS
			    || area.inspect(row - i, col + j) == DEBRIS) {
				return RIGHT;
			}
			if (area.inspect(row + i, col - j) == DEBRIS
			    || area.inspect(row - i, col - j) == DEBRIS) {
				return LEFT;
			}
		}
		// if there is one robot there are more options
		if (NUM == 1) {
			if (DebrisIsNear(i, loc, area) == "ONEDOWN") {
				return DOWN;
			}
			if (DebrisIsNear(i, loc, area) == "ONEUP") {
				return UP;
			}
			if (DebrisIsNear(i, loc, area) == "ONERIGHT") {
				return RIGHT;
			}
			if (DebrisIsNear(i, loc, area) == "ONELEFT") {
				return LEFT;
			}
		}
	}
	// if neither a broken robot or debris can be found then
	// robots will move in a non chaotic way to find any missing debris
	// robot will move LEFT or RIGHT if there are more rows than columns
	if (ROWS >= COLS) {
		if (cycle == false) {
			if (col == 0) {
				cycle = true;
			}
			return LEFT;
		}
		if (cycle == true) {
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
			if (col == COLS - 1) {
				cycle = false;
			}
			return RIGHT;
		}
	}
	// robot will move  UP or DOWN if there are more columns than rows
<<<<<<< HEAD
=======
	// perhaps do a second cycle and retry the half thingy
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
	if (COLS > ROWS) {
		if (cycle == false) {
			if (row == 0) {
				cycle = true;
			}
			return UP;
		}
		if (cycle == true) {
			if (row == ROWS - 1) {
				cycle = false;
			}
<<<<<<< HEAD
			return DOWN;
		}
	}
	// if not at a debris field, move randomly:
	switch (rand() % 4) {
		case 0:
			return LEFT;
		case 1:
			return RIGHT;
		case 2:
			return UP;
		default:
=======
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
			return DOWN;
	}
}
<<<<<<< HEAD
}
=======
}
>>>>>>> fc4420f671f8fb9f0fa33b3c634027ca30989c24
void onRobotMalfunction(int id, Loc loc, Area& area, ostream& log) {
	log << "Robot " << id << " is damaged." << endl;
	// make it known in the array that the current robot ID is broken
	robot_status[id] = broken;
}
void onClockTick(int time, ostream& log) {
	if (time % 100 == 0)
		log << time << " ";
}
