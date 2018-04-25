//Author: Marin Pavlinov Marinov
//Course: Csci-135
//Instructor: Genady Maryashi
//Assignment: project 3

#include <cstdlib>
#include <iostream>
#include "bot.h"

using namespace std;

const int MAX_ROBOT_NUM = 50;
int NUM;          // to remember number or robots
int ROWS, COLS;  // map dimensions
bool working=false;   //to input
bool broken=true;
//array to store robot id's and determine whether they are working or not
bool robot_status[50];
//global variable to make the robots cycle up,down left or right(depending on ROWS AND COLS) instead of moving chaotically
bool cycle=false;


/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;
	for(int i=0;i<50;i++)
	{
		//make all robots working at the start
		robot_status[i]=working;
	}
	log << "Start!" << endl;
}


///////checks to see if a robot is next to a robot
string botNextToBot(int id,int id_2,Loc loc,Area &area)
{
	if (id_2!=id)
	{
		if (area.locate(id_2).r==area.locate(id).r+1  && area.locate(id_2).c==area.locate(id).c)
		{
			return "BotUP";
		}
		if (area.locate(id_2).r==area.locate(id).r-1  && area.locate(id_2).c==area.locate(id).c)
		{
			return "BotDOWN";
		}
		if (area.locate(id_2).r==area.locate(id).r && area.locate(id_2).c==area.locate(id).c+1 )
		{
			return "BotLEFT";
		}
		if (area.locate(id_2).r==area.locate(id).r && area.locate(id_2).c==area.locate(id).c-1 )
		{
			return "BotRIGHT";
		}
	}
	return "NONE";
}


//finds the broken robots row and column coardinates and then stores them
Loc findBrokenRobot(Loc loc,Area &area)
{
	Loc def;
	for (int i=0;i<NUM;i++)
	{
		if (robot_status[i]==broken)
		{
			//return the coardinates
			def.r = area.locate(i).r;
			def.c = area.locate(i).c;
			return def;
		}
	}
	//if no broken robot is found then it returns non existant coardinates
	def.r=-1;
	def.c =-1;
	return def;
}



//compares Locs coardinates
bool locEquals(Loc thisL, Loc otherL){
	if (thisL.r == otherL.r && thisL.c == otherL.c)
	{
		return true;
	}
	return false;
}


//finds the  debris that is d units away,in a circle
string DebrisIsNear(int d,Loc loc,Area &area)
{
	int row=loc.r;
	int col=loc.c;

	if (area.inspect(row,col+d)==DEBRIS)
	{
		return "RIGHT";
	}
	if (area.inspect(row+d,col)==DEBRIS)
	{
		return "DOWN";
	}
	if (area.inspect(row-d,col)==DEBRIS)
	{
		return "UP";
	}
	if (area.inspect(row,col-d)==DEBRIS)
	{
		return "LEFT";
	}
	//one coardinate up,down,left, or right and d units away
	if (area.inspect(row+1,col+d)==DEBRIS ||area.inspect(row+1,col-d)==DEBRIS)
	{
		return "ONEDOWN";
	}
	if (area.inspect(row+d,col+1)==DEBRIS || area.inspect(row-d,col+1)==DEBRIS)
	{
		return "ONERIGHT";
	}
	if (area.inspect(row-1,col+d)==DEBRIS || area.inspect(row-1,col-d)==DEBRIS)
	{
		return "ONEUP";
	}
	if (area.inspect(row+d,col-1)==DEBRIS || area.inspect(row-d,col-1)==DEBRIS)
	{
		return "ONELEFT";
	}
	return "NOTHING";
}


/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log)
{
	int row = loc.r; // current row and column
	int col = loc.c;

	if (area.inspect(row, col) == DEBRIS)
	{
		return COLLECT;
	}
 		//Fix a robot if it breaks down
		// Loc broken = findBrokenRobot(loc,area);
		// if (loc.r == broken.r-1 && loc.c == broken.c)
		// {
		// 	return REPAIR_DOWN;
		// }
		// if (loc.r == broken.r+1 && loc.c == broken.c)
		// {
		// 	return REPAIR_UP;
		// }
		// if (loc.r == broken.r && loc.c == broken.c-1)
		// {
		// 	return REPAIR_RIGHT;
		// }
		// if (loc.r == broken.r && loc.c == broken.c+1)
		// {
		// 	return REPAIR_LEFT;
		// }
		////////////////////////////////////////////////////////
		for (int id_2=0;id_2<50;id_2++)
		{
			if (botNextToBot(id,id_2,loc,area)=="BotUP")
			{
				if (robot_status[id_2]==broken)
				{
					robot_status[id_2]=working;
					return REPAIR_DOWN;
				}
				log<<" UP  ";
				for (int i=0;i<40;i++)
				{
					if (DebrisIsNear(i,loc,area)=="UP")
		 		 	{
		 				return UP;
		 			}
		 			if (DebrisIsNear(i,loc,area)=="LEFT")
		 			{
		 				return LEFT;
		 			}
					if (DebrisIsNear(i,loc,area)=="RIGHT")
					{
						return RIGHT;
					}
				}
			}
			if (botNextToBot(id,id_2,loc,area)=="BotDOWN")
			{
				if (robot_status[id_2]==broken)
				{
					robot_status[id_2]=working;
					return REPAIR_UP;
				}
				log<<" down   ";
				for (int i=0;i<40;i++)
				{
					if (DebrisIsNear(i,loc,area)=="LEFT")
		 			{
		 				return LEFT;
		 			}
					if (DebrisIsNear(i,loc,area)=="RIGHT")
					{
						return RIGHT;
					}
					if (DebrisIsNear(i,loc,area)=="DOWN")
					{
						return DOWN;
					}
				}
			}

			if (botNextToBot(id,id_2,loc,area)=="BotLEFT")
			{
				if (robot_status[id_2]==broken)
				{
					robot_status[id_2]=working;
					return REPAIR_RIGHT;
				}
				log<<"LEFT   ";
				for (int i=0;i<40;i++)
				{
					if (DebrisIsNear(i,loc,area)=="DOWN")
					{
						return DOWN;
					}
					if (DebrisIsNear(i,loc,area)=="UP")
		 		 	{
		 				return UP;
		 			}
		 			if (DebrisIsNear(i,loc,area)=="LEFT")
		 			{
		 				return LEFT;
		 			}
				}
			}
			if (botNextToBot(id,id_2,loc,area)=="BotRIGHT")
			{
				if (robot_status[id_2]==broken)
				{
					robot_status[id_2]=working;
					return REPAIR_LEFT;
				}
				log<<"RIGHT  ";
				for (int i=0;i<40;i++)
				{
					if (DebrisIsNear(i,loc,area)=="RIGHT")
					{
						return RIGHT;
					}
					if (DebrisIsNear(i,loc,area)=="DOWN")
					{
						return DOWN;
					}
					if (DebrisIsNear(i,loc,area)=="UP")
		 		 	{
		 				return UP;
		 			}
				}
			}
		}

//inspect area around the robot, find a Debris that is near and go towards it
//this matches the brute force but can be improved
		for(int i=0;i<40;i++)
		{
			if (DebrisIsNear(i,loc,area)=="RIGHT")
			{
				return RIGHT;
			}
			if (DebrisIsNear(i,loc,area)=="DOWN")
			{
				return DOWN;
			}
			if (DebrisIsNear(i,loc,area)=="UP")
 		 	{
 				return UP;
 			}
 			if (DebrisIsNear(i,loc,area)=="LEFT")
 			{
 				return LEFT;
 			}
			///one turn for it to be in a stright line
			// if (DebrisIsNear(i,loc,area)=="ONEDOWN")
 			// {
 			// 	return DOWN;
 			// }
			// if (DebrisIsNear(i,loc,area)=="ONEUP")
			// {
			// 	return UP;
			// }
			// if (DebrisIsNear(i,loc,area)=="ONELEFT")
			// {
			// 	return LEFT;
			// }
			// if (DebrisIsNear(i,loc,area)=="ONERIGHT")
			// {
			// 	return RIGHT;
			// }
		}
//if a robot is next to another robot and that robot is not broken....
		//When the above conditions are not satisfied...
		//robot will move LEFT or RIGHT if there are more rows than columns
		if (ROWS >= COLS)
		{
			if (cycle==false)
			{
				if (col==0)
				{
					cycle=true;
				}
				return LEFT;
			}
			if (cycle==true)
			{
				if (col==COLS-1)
				{
					cycle=false;
				}
				return RIGHT;
			}
		}
		//robot will move  UP or DOWN if there are more columns than rows
		//perhaps do a second cycle and retry the half thingy
		if (COLS > ROWS)
		{
			if (cycle==false)
			{
				if (row==0)
				{
					cycle=true;
				}
				return UP;
			}
			if (cycle==true)
			{
				if (row==ROWS-1)
				{
					cycle=false;
				}
				return DOWN;
			}
		}
		//if not at a debris field, move randomly:
		switch(rand() % 4)
    {
			case 0:
				return LEFT;
			case 1:
				return RIGHT;
			case 2:
				return UP;
			default:
				return DOWN;
		}
}
void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log)
{
	log << "Robot " << id << " is damaged." << endl;
	//make it known in the array that the current robot ID is broken
	robot_status[id]=broken;
}
void onClockTick(int time, ostream &log)
{
	if (time % 100 == 0) log << time << " ";
}
