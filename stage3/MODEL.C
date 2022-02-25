#include <stdio.h>
#include <osbind.h>
#include "model.h"

void movePlayer(struct player *playChar){
	playChar->x += playChar->xVelocity;
	playChar->y += playChar->yVelocity;
	
	/*Potentially add something later along the
	lines of reducing the velocity after this add*/
	return;
}

void moveCrystal(struct crystal *inPlay, int newXCord, int newYCord){
	inPlay->x = newXCord;
	inPlay->y = newYCord;
	
	return;
}

void changeScore(struct score *score, int addToScore){
	score->score += addToScore;
	
	/*TODO: add function to update to screen at later stage.*/
	return;
}

void changeTime(struct timeRemaining *timeLeft){
	if (timeLeft->ticks < fps) {
		timeLeft->ticks += 1;
	}
	else {
		timeLeft->wholeSeconds -= 1;
		timeLeft->ticks = 0;
	}
	/*This implamentation sucks, will have to be revisited later.*/
	return;
}
