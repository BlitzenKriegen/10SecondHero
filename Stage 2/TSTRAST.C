#include <stdio.h>
#include <osbind.h>
#include "raster.h"

int main(){
    UINT16 *base = (UINT16*) Physbase();
    UINT8 *pixel = (UINT8 *) Physbase();
    UINT16 test_blackout[16]=
    {
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF,
	0xFFFF
    };

    int height = BITMAP_HEIGHT;
    int x;
    int y;
	drawHorizontal(base,320,200,test_blackout,height,5);
	drawVertical(base,220,200,test_blackout,height,5);
	clearScreen(base);
	drawPixel(pixel,320,200);
    return 0;
}
