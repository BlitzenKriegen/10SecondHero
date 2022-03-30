#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"
#include "event.h"

#define CLOCK 0x462
#define MAX_HEIGHT 16

typedef unsigned long ULONG32;
    
ULONG32 getTime();

/*void keyInput(struct Model *model, UINT16 *base, int x, int y, long input); */

void processAsyncEvents(struct Model *model);
void processSyncEvents(struct Model *model);

bool gameIsRunning = true;

int main(){
	int oldX = 0;
	int oldY = 0;
	ULONG32 timeNow, timeThen, timeElapsed,
		fallTime, currFallTicks, timerTime, currTimerTicks;
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	unsigned long currInput = 0x00000000;

	/*Vsync();*/
	timeThen = getTime();
	currFallTicks = timeThen;
	currTimerTicks = timeThen;
	render(&tenSecondHero,base);

	while(gameIsRunning){
		oldX = tenSecondHero.player.x;
		oldY = tenSecondHero.player.y;
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
		fallTime = timeNow - currFallTicks;
		timerTime = timeNow - currTimerTicks;
		/* Sync events*/
		if (timeElapsed > 0)
		{
			timeNow = getTime();
			timeThen = timeNow;

			if (isTimer0(tenSecondHero))
			{
				gameIsRunning = false;
			}
			crystalCollected(&tenSecondHero);
			
			if (fallTime >= 20) /* have falling happen every x ticks?*/
			{
				fallTime = getTime();
				playerFall(&tenSecondHero);
			}
			Vsync(); /* this somehow stops multiple plotting */
			renderMovable(&tenSecondHero, oldX, oldY, base);
		}
	}

	return 0;
}

/*
void keyInput(struct Model *model, UINT16 *base, int OldX, int OldY, long tst){
	Direction playDirec;
		if(tst == 'a'){
			playDirec = left;
		}
		else if(tst == 'd'){
			playDirec = right;
		}
		else if(tst == ' '){
			playerJump(model);
		}
		plotBitmap16(base,OldX,OldY,CLEAR_BITMAP,MAX_HEIGHT);
		playerRun(model,playDirec);
	return;
}
*/

ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}