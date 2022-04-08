#include "const.h"
#include "psg.h"
#include "music.h"

UINT8 tstMelody[8] = {150,165,180,195,210,225,240,250};

void start_music(){
	set_tone(0,tstMelody[0]);
	set_tone(1,0);
	enable_channel(0,1,0);
	set_volume(8,11);
	
	return;
}