#include "renderer.h"
#define MAX_HEIGHT 16

int main(){
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	render(&tenSecondHero,base);
	return 0;
}

void renderPlayer(const struct Player *Player,UINT16 *base){
	plotBitmap16(base,Player->x,Player->y,PLAYER_BITMAP,MAX_HEIGHT);
	return;
}

void renderCrystal(const struct Crystal *crystal,UINT16 *base){
	plotBitmap16(base,crystal->x,crystal->y,CRYSTAL_BITMAP,MAX_HEIGHT);
	return;
}

void renderPlatform(const struct Platform platform[],UINT16 *base){
	int i = 0;
	printf("Val: %d\n",platform[i].x);
	for (i = 0;i < 6; i++) {
		drawHorizontal(base,platform[i].x,
		platform[i].y, BLACKOUT_BITMAP, MAX_HEIGHT, platform[i].length);	
	}
	return;
}

void renderTimer(const struct TimeRemaining *timeLeft, UINT16 *base){
	plotBitmap16(base,timeLeft->x,timeLeft->y,BLACKOUT_BITMAP,MAX_HEIGHT);
	return;
}

void renderScore(const struct Score *score,UINT16 *base){
	plotBitmap16(base,score->x,score->y,BLACKOUT_BITMAP,MAX_HEIGHT);
	return;
}

void render(const struct Model *model, UINT16 *base){
	clearScreen();
	initModel(model);
	renderPlatform(model->platforms,base);
	
	renderPlayer(&model->player,base);	
	renderCrystal(&model->crystal,base);
	renderTimer(&model->timeLeft,base);
	renderScore(&model->score,base);
	
	return;
}