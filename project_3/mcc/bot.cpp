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
int ROWS, COLS;   // map dimensions

// int row_Destination(MAX_ROBOT_NUM)={};
//
// int col_Destination(MAX_ROBOT_NUM)={};
// bool robot_needs_location[MAX_ROBOT_NUM]={false};


/* Initialization procedure, called when the game starts: */
void onStart(int num, int rows, int cols, double mpr,Area &area, ostream &log)
{
	NUM = num;   // save the number of robots and the map dimensions
	ROWS = rows;
	COLS = cols;

	log << "Start!" << endl;
}

/* Deciding robot's next move */
Action onRobotAction(int id, Loc loc, Area &area, ostream &log)
{
	int row = loc.r; // current row and column
	int col = loc.c;

	if (area.inspect(row, col) == DEBRIS)
		return COLLECT;
	//if the debris is either one square away, go to it
  else if (area.inspect(row+1,col)==DEBRIS)
  {
    return DOWN;
  }
  else if (area.inspect(row, col+1)==DEBRIS)
  {
    return RIGHT;
  }
  else if (area.inspect(row-1, col)==DEBRIS)
  {
    return UP;
  }
  else if (area.inspect(row,col-1)==DEBRIS)
  {
    return LEFT;
  }
	//next set	of statements check for DEBRIS that is farther away
	else
  {
		////if its just one column and row away, zig zag towards it
	 if (area.inspect(row+1,col+1)==DEBRIS)
		{
			switch (rand() % 2)
			{
				case 0:
					return DOWN;
				case 1:
					return RIGHT;
			}
		}
		else if (area.inspect(row+1,col-1)==DEBRIS)
		{
			switch (rand() % 2)
			{
				case 0:
					return DOWN;
				case 1:
					return LEFT;
			}
		}
		else if (area.inspect(row-1,col+1)==DEBRIS)
		{
			switch (rand() % 2)
			{
				case 0:
					return UP;
				case 1:
					return RIGHT;
			}
		}
		else if (area.inspect(row-1,col-1)==DEBRIS)
		{
			switch (rand() % 2)
			{
				case 0:
					return UP;
				case 1:
					return LEFT;
			}
		}
		//////////////////////////////////////////////////////////
		//when a Debris is near either hori, go straight towards it
		for (int j=COLS;j>1;j--)//these for loops check how many columns  and rows the robot is away from the debris
		{
					//each if statement corresponds to the proper way the robot should zig zag towards the debris
			if (area.inspect(row,col+j)==DEBRIS)
			{
					return RIGHT;
			}
		}
		///////////////////////////////////
		for (int k=COLS;k>1;k--)
		{
			if(area.inspect(row,col-k)==DEBRIS)
			{
					return LEFT;
			}
		}
		///////////////////////////////
		for (int i=ROWS;i>1;i--)
		{
			if(area.inspect(row+i,col)==DEBRIS)
			{
				return DOWN;
			}
		}
		///////////////////////////////
		for (int x=ROWS;x>1;x--)
		{
			if(area.inspect(row-x,col)==DEBRIS)
			{
				return UP;
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
}

void onRobotMalfunction(int id, Loc loc, Area &area, ostream &log)
{
	log << "Robot " << id << " is damaged." << endl;
}

void onClockTick(int time, ostream &log)
{
	if (time % 100 == 0) log << time << " ";
}
