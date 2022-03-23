/*
Names:  	Enrik R
			Kiril S
Module:		Model 
Purpose: 	The renderer module contains the subroutine and function calls related to the 
			output of current gamestate to the screen. 
Details: 	A model structure is created and initialized to set values from const.h,
			const.c and model.c. The model then gets printed onto the screen via 16x16
			bitmaps.
*/
#include "renderer.h"
#define MAX_HEIGHT 16
#define POS2 16
#define POS3 32
#define POS4 48
#define POS5 64
#define POS6 80

/*test driver to create the gamestate
int main(){
	struct Model tenSecondHero;
	UINT16 *base = Physbase();
	render(&tenSecondHero,base);
	return 0;
}*/

/*
Subroutine: renderPlayer
Input Parameters: Player
					Pointer to the player structure controlled by the user.
				  base
					Pointer to the start of the frame buffer.
Purpose: Print the player bitmap onto the screen.
Details: Passing in the player and the framebuffer, the function
calls the bitmap plot function to display the designated bitmap onto the
screen at the coordinates within the player structure.
*/
void renderPlayer(const struct Player *Player,UINT16 *base){
	plotBitmap16(base,Player->x,Player->y,PLAYER_BITMAP,MAX_HEIGHT);
	return;
}

/*
Subroutine: renderCrystal
Input Parameters: Player
					Pointer to the crystal structure within the game.
				  base
					Pointer to the start of the frame buffer.
Purpose: Print the crystal bitmap onto the screen.
Details: Passing in the crystal and the framebuffer, the function
calls the bitmap plot function to display the designated bitmap onto the
screen at the coordinates within the crystal structure.
*/
void renderCrystal(const struct Crystal *crystal,UINT16 *base){
	plotBitmap16(base,crystal->x,crystal->y,CRYSTAL_BITMAP,MAX_HEIGHT);
	return;
}

/*
Subroutine: renderPlatform
Input Parameters: platform
					Array of platforms in the gamestate.
				  base
					Pointer to the start of the frame buffer.
Purpose: Print all platforms onto the screen.
Details: Passing in the platform and the framebuffer, the function
goes into a for loop that processes every platform within the array
and puts them onto the screen.
*/
void renderPlatform(const struct Platform platform[],UINT16 *base){
	int i = 0;
	for (i = 0;i < 6; i++) {
		drawHorizontal(base,platform[i].x,platform[i].y,
		BLACKOUT_BITMAP, MAX_HEIGHT, platform[i].length);	
	}
	return;
}

/*
Subroutine: renderTimer
Input Parameters: timeLeft
					The timer structure in the gamestate.
				  base
					Pointer to the start of the frame buffer.
Purpose: Print the Time onto the screen.
Details: Passing in the timer and the framebuffer, the function
prints TIME onto the left, upmost corner of the screen. Note that the
actual time will be dealt with at a later date once the game
is synced to the clock.
*/
void renderTimer(const struct TimeRemaining *timeLeft, UINT16 *base){
	plotBitmap16(base,timeLeft->x,timeLeft->y,LETTER_T,MAX_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS2,timeLeft->y,LETTER_I,MAX_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS3,timeLeft->y,LETTER_M,MAX_HEIGHT);
	plotBitmap16(base,(timeLeft->x)+POS4,timeLeft->y,LETTER_E,MAX_HEIGHT);
	return;
}

/*
Subroutine: renderTimer
Input Parameters: score
					The score structure in the gamestate.
				  base
					Pointer to the start of the frame buffer.
Purpose: Print the Score onto the screen.
Details: Passing in the score and the framebuffer, the function
prints SCORE onto the right, upmost corner of the screen. Note that the
actual score will be dealt with at a later date once the player is actually
able to score.
*/
void renderScore(const struct Score *score,UINT16 *base){
	plotBitmap16(base,score->x,score->y,LETTER_S,MAX_HEIGHT);
	plotBitmap16(base,(score->x)+POS2,score->y,LETTER_C,MAX_HEIGHT);
	plotBitmap16(base,(score->x)+POS3,score->y,LETTER_O,MAX_HEIGHT);
	plotBitmap16(base,(score->x)+POS4,score->y,LETTER_R,MAX_HEIGHT);
	plotBitmap16(base,(score->x)+POS5,score->y,LETTER_E,MAX_HEIGHT);
	return;
}

/*
Subroutine: render
Input Parameters: model
					The Gamestate and all structures accociated with it.
Purpose: Initialises the gamestate to the starting position.
Details: The function clears the screen before initializing the gamestate to
a starting position. When this has finished, the function then goes on to
output the gamestate to the user, with every substructure within model being
"rendered".
*/
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
