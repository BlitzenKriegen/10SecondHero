#include "model.h"
#include "event.h"

int main()
{
	struct Model test10SecondHero;
	initModel(&test10SecondHero);


	

	/* This tests the playerRun function. WORKS.
	printf("player x: %u \n", test10SecondHero.player.x);
	playerRun(&test10SecondHero.player);
	printf("new player x: %u \n", test10SecondHero.player.x);
	
	/* This tests the crystalMove function, WORKS
 	printf("crystal x: %u \n", test10SecondHero.crystal.x);
	moveCrystal(&test10SecondHero.crystal, 13, 27);
	printf("new crystal x: %u \n", test10SecondHero.crystal.x);
	
	/* This tests the decreaseTime function, WORKS */
 	printf("timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	decreaseTime(&test10SecondHero.timeLeft);
	printf("new timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	
	/* This tests the increaseTime function, WORKS */
 	printf("timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	increaseTime(&test10SecondHero.timeLeft);
	printf("new timer time: %u \n", test10SecondHero.timeLeft.wholeSecs);
	
	/* This tests the increaseScore function, WORKS
 	printf("score amt: %u \n", test10SecondHero.score.scoreAmnt);
	increaseScore(&test10SecondHero.score);
	printf("new score amt: %u \n", test10SecondHero.score.scoreAmnt);
	*/
	
    return 0;
}

