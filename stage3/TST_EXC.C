#include <stdio.h>
#include <osbind.h>
#include "model.h"
#include "event.h"

int main()
{
	Model test10SecondHero;
	initModel(test10SecondHero);

	printf("player x:", test10SecondHero->player->x);
	playerRun(test10SecondHero->player);
	printf("new player x:", test10SecondHero->player->x);
 
    return 0;
}