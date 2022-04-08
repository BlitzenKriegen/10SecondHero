/*
Names:  	Enrik Rushiti
			Kiril Sikov

Module:		Hero

Purpose: 	Contains the main game loop.
*/
#include "hero.h"
const UINT8 buffer2[BUFFER_256];
const UINT8 staticBuffer[BUFFER_SIZE]; 

int main(){
	UINT16 *base1 = getVideoBase();
	UINT16 *base2;
	UINT16 *staticBuffPtr = (UINT16 *)staticBuffer;
	UINT16 offset;
	UINT16 align;
	UINT16 *ptr = staticBuffPtr;
	bool gameIsRunning = true;
	ULONG32 timeNow, timeThen, timeElapsed, timerTime, currTimerTicks;
	struct Model tenSecondHero;
	unsigned long currInput = 0;
	bool swapBuff = true;
	srand(SRAND_TEST_KEY);
	initModel(&tenSecondHero);
	
	offset = (UINT16)buffer2;
	align = offset % 256;
	base2 = (UINT16 *)(buffer2 + (256 - align));
	
	timeThen = getTime();
	currTimerTicks = timeThen;
	
	renderStatic(&tenSecondHero,staticBuffPtr);

	while(gameIsRunning && tenSecondHero.score.scoreAmnt <= MAX_SCORE){
		/* Async events*/
		if (Cconis())
		{
			currInput = Cnecin();	
			if (currInput == ESC_KEY)
			{
				gameIsRunning = false;
			} else
			{
				movePlayer(&tenSecondHero, currInput);
			}		
		}

		timeNow = getTime();
		timeElapsed = timeNow - timeThen;
		timerTime = timeNow - currTimerTicks;

		/* Sync events*/
		if (timeElapsed > 0)
		{
			timeNow = getTime();
			timeThen = timeNow;
				
			processSyncEvents(&tenSecondHero, &currTimerTicks,
				&timerTime, &gameIsRunning);
			if (swapBuff)
			{
				memcpy(base1, staticBuffPtr, BUFFER_SIZE);
				renderMovable(&tenSecondHero, base1);
				setVideoBase(base1);
				
				Vsync();
			} else
			{
				memcpy(base2, staticBuffPtr, BUFFER_SIZE);
				renderMovable(&tenSecondHero, base2);
				setVideoBase(base2);
				
				Vsync();
			}
			swapBuff = !swapBuff;
		}
	}
	setVideoBase(base1);
	return 0;
}

void processSyncEvents(struct Model *model, ULONG32 *currTimerTicks, 
	ULONG32 *timerTime, bool *gameIsRunning)
{
	playerFall(model);			
	if (*timerTime >= SECOND_TICK) 
	{
		*currTimerTicks = getTime();
		tickTimeDown(model);
	}
			
	playerRun(model);
	crystalCollected(model);
	if (isTimer0(*model))
	{
		*gameIsRunning = false;
	}
}

ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}