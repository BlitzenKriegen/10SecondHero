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
#include <stdio.h>
#include <osbind.h>
#include "model.h"
#include "event.h"

/*void playerJump (struct Player *playChar) */

/* void playerFall (struct Player *playChar)	for future development*/

void playerRun(Player *playChar)
{
	playChar->x += playChar->xVelocity;
	playChar->y += playChar->yVelocity;
	/* also dont let running incrase/decrease y values,
	only jumping/falling affects y values */
	
	
	/*Potentially add something later along the
	lines of reducing the velocity after this add*/
}

void moveCrystal(Crystal *playCrystal, int newXCord, int newYCord)
{
	playCrystal->x = newXCord;
	playCrystal->y = newYCord;
}

void increaseScore(Score *score)
{
	score->scoreAmnt += SCORE_ADD;
	
	/*TODO: add function to update to screen at later stage.*/
}

void decreaseTime(TimeRemaining *timeLeft)
{
	if (timeLeft->ticks < fps)
	{
		timeLeft->ticks += 1;
	}
	else
	{
		timeLeft->wholeSeconds -= 1;
		timeLeft->ticks = 0;
	}
	/*This implementation sucks, will have to be revisited later.*/
}

void increaseTime(TimeRemaining *timeLeft)
{
	timeLeft->wholeSeconds += TIME_SECS_ADD;
}

/* not complete, need to add more in the future*/
void initPlatform(Platform *platform, initX, initY, initLength)
{
	platform->x = initX;
	platform->x = initY;
	platform->x = initLength;
}
	

void initPlayer(Player *playChar)
{
	playChar->x = PLAYER_X;
	playChar->y = PLAYER_Y;
	playChar->xVelocity = PLAYER_X_VEL;
	playChar->yVelocity = PLAYER_Y_VEL;
}	

void initCrystal(Crystal *crystal)
{
	crystal->x = CRYSTAL_X;
	crystal->y = CRYSTAL_Y;
	crystal->playerContact = CRYSTAL_CONTACT;
}	

void initTimer(TimeRemaining *timeLeft)
{
	timeLeft->x = TIMER_X;
	timeLeft->y = TIMER_Y;
	timeLeft->wholeSeconds = TIMER_SECS;
	timeLeft->ticks = TIMER_TICKS;
}	

void initScore(Score *score)
{
	score->x = SCORE_X;
	score->y = SCORE_Y;
	score->scoreAmnt = SCORE_AMNT;
}

void initModel(Model *model)
{
	initPlatform(model->platforms[GROUND]);
	initPlatform(model->platforms[1]);
	initPlatform(model->platforms[2]);
	initPlatform(model->platforms[3]);
	initPlatform(model->platforms[4]);
	initPlatform(model->platforms[5]);
	
	initPlayer(model->player);
	
	initCrystal(model->crystal);
	
	initScore(model->score);
	
	initTimer(model->timeLeft);
	
	isTimer0 = false;
}	

