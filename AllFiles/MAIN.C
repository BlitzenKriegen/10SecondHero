#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"

#define CLOCK 0x462
#define ESC_ASCII 27
#define MAX_HEIGHT 16

typedef unsigned long ULONG32;
    
ULONG32 getTime();
void keyInput(struct Model *model, UINT16 *base,struct Model *last, char input);

void processAsyncEvents(struct Model *model);
void processSyncEvents(struct Model *model);

int main(){
	ULONG32 timeNow, timeThen, timeElapsed;
	struct Model tenSecondHero;
	struct Model lastFrame;
	UINT16 *base = Physbase();
	char inp = NULL;
	bool quit = false;

	Vsync();
	render(&tenSecondHero,base);
	timeThen = getTime();
	/*For future use as the game state loop.
	when the user hits the escape button, the game
	will immediately exit.*/
	while(!quit){
		timeNow = getTime();
		if(timeNow - timeThen > 0){
			timeThen = timeNow;
			processSyncEvents(&tenSecondHero);
			renderMovable(&tenSecondHero,&lastFrame,base);
			timeNow = getTime();
		}
		if(Cconis()){
			inp = (char)Cconin();
			if(inp == ESC_ASCII){
				quit = true;
			}
			else {
				processAsyncEvents(&tenSecondHero);
			}
		}
	}
	return 0;
}

void keyInput(struct Model *model, UINT16 *base, struct Model *last, char tst){
	Direction playDirec;
	int OldX = last->player.x;
	int OldY = last->player.y;
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

ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}


void processAsyncEvents(struct Model *model)
{

	return;
}


void processSyncEvents(struct Model *model)
{
	playerFall(model);
	return;
}