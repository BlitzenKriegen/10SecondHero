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
void keyInput(struct Model *model, UINT16 *base, int x, int y,char input);

int main(){
	int oldX = 0;
	int oldY = 0;
	ULONG32 timeNow;
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	char tst = NULL;

	Vsync();
	timeNow = getTime();
	render(&tenSecondHero,base);
	/*For future use as the game state loop.
	when the user hits the escape button, the game
	will immediately exit.*/
	while(tst != ESC_ASCII){
		oldX = tenSecondHero.player.x;
		oldY = tenSecondHero.player.y;
		playerFall(&tenSecondHero);
		renderMovable(&tenSecondHero,oldX,oldY,base);
		if(Cconis()){
			tst = (char)Cnecin();
			keyInput(&tenSecondHero,base,oldX,oldY,tst);
		}
	}

	return 0;
}

void keyInput(struct Model *model, UINT16 *base, int OldX, int OldY, char tst){
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

ULONG32 getTime(){
	long old_ssp;
	ULONG32 timeNow;
	long *timer = (long *)CLOCK;

	old_ssp = Super(0);
	timeNow = *timer;
	Super(old_ssp);
	return timeNow;
}