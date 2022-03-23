#include <osbind.h>
#include <stdio.h>
#include "const.h"
#include "renderer.h"
#include "model.h"

#define CLOCK 0x462

typedef unsigned long ULONG32;

ULONG32 getTime();

int main(){
	long old_ssp;
	ULONG32 timeNow;
	struct Model tenSecondHero;
	UINT16 *base = Physbase();

	timeNow = getTime();
	render(&tenSecondHero,base);
	printf("timer: %d\n",timeNow);

	return 0;
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