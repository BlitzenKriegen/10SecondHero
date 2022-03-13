/*
Names:  	Enrik R
			Kiril S

Module:		Model 

Purpose: 	The model module contains the structs and functions related to the 
			model of the game, and the functions that directly impact the model. 

Details: 	The model is not responsible for handling events, whether they be
			synchronous, asychronous, or conditional. The model handles the
			behaviours or actions that result from those events occuring.
			Ex: Space bar is pressed (event) = player jumps (action)
*/


#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <osbind.h>
#include "const.h"

struct Hitbox{
    UINT16 top_left_x;
    UINT16 top_left_y;
    UINT16 bottom_right_x;
    UINT16 bottom_right_y;
    UINT16 width;
    UINT16 height;
    /*bool collected;    maybe use this for crystal at some point*/
};


/*The following structure represents a platform 
within 10 Second Hero. The platform is defined by 
three parameters. The two parameters are the x and
y coordinates of where the platform would begin to be
drawn. Length is a whole number that represents how 
long a platform could be. For example, assuming the 
length is 3, the platform would be drawn BASE_LEN*length 
long, where BASE_LEN is the base length of the platform.*/
struct Platform
{
	unsigned int x;			
	unsigned int y;			
	unsigned int length;
	
};

/*The following structure represents the player
character within 10 second hero, sans its bitmap.
x and y represent the coordinates of the player, while
xVel and yVel represent the directional movement of the
player per game tick. Negatives represent left and down
respectively, while positive values represent right and
up, again respectively.*/
struct Player
{
	unsigned int x;
	unsigned int y;
	int xVelocity;
	int yVelocity;
};

/*The following strucutre represents the collectable
crystal within the game. Once again, x and y represent
the coordinates of the crystal, while playerContact
represent if the player is "touching" the hitbox of the
crystal. This value would be 0 if the player is not in
contact with the crystal, while it would be 1 were the
player to come in contact with the crystal.*/
struct Crystal
{
	unsigned int x;
	unsigned int y;
	bool playerContact;
};

/*The following structure represents the timer within
10 second hero. Currently, this holds the x and y cordinate
of the byte wholeSeconds, which represents the remaining time.
Each game tick, the time gets subtracted by 
1/(Game ticks per second).*/
struct TimeRemaining
{
	unsigned int x;
	unsigned int y;
	unsigned int wholeSecs;
	unsigned int ticks;
	/*unsigned char tenthSeconds;		for future development
	unsigned char hundrethSeconds;*/
};

/*The following structure holds the score of the played game.
x and y represent the coordinates of the scoreboard, while
score itself is the numeric representation of the points
attained by the player.*/

struct Score
{
	unsigned int x;
	unsigned int y;
	unsigned int scoreAmnt;
};


struct Model
{
	struct Player player;
	struct Crystal crystal;
	struct Platform platforms[6]; /* 0 is ground platform */
	struct Score score;
	struct TimeRemaining timeLeft;
	bool isTimer0;
};


/* void playerJump (struct Player *playChar)	for future development*/

/* void playerFall (struct Player *playChar)	for future development*/

void playerRun(struct Player *playChar);

void moveCrystal(struct Crystal *inPlay, int newXCord, int newYCord);

void increaseScore(struct Score *score);

void decreaseTime(struct TimeRemaining *timeLeft);

void increaseTime(struct TimeRemaining *timeLeft);

/* initiliziers*/
void initPlatform(struct Platform *platform, int initX, int initY, int initLength);	

void initPlayer(struct Player *playChar);		

void initCrystal(struct Crystal *crystal);	

void initScore(struct Score *score);	

void initTimer(struct TimeRemaining *timeLeft);	

void initModel(struct Model *model);	

#endif