#include "renderer.h"

int main(){
	struct Model *tenSecondHero;
	UINT16 *base = Physbase();
	render(tenSecondHero,base);
	return 0;
}

void render_player(const struct Player *Player,UINT16 *base){
	
	return;
}

void render_crystal(const struct Crystal *crystal,UINT16 *base){
	
	return;
}

void render_platform(const struct Platform *platform[],UINT16 *base){
	
	return;
}

void render_timer(const struct TimeRemaining *timeLeft, UINT16 *base){
	return;
}

void render_score(const struct Score *score,UINT16 *base){
	
	return;
}

void render(const struct Model *model, UINT16 *base){
	initModel(model);
	render_player(&model->player,base);
	render_platform(&model->platforms,base);
	render_crystal(&model->crystal,base);
	render_timer(&model->timeLeft,base);
	render_score(&model->score,base);
	return;
}