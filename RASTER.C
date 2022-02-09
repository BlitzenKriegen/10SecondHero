#include <stdio.h>
#include <osbind.h>
#include <"raster.h">

#define BITMAP_HEIGHT 16
#define XBOUNDS 640
#define YBOUNDS 400

int main(){
    UINT16 *base = (UINT16*) Physbase();
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
    return 0;
}

void clearScreen(UINT16 *base){
	int x;
	int y;
	int height = BITMAP_HEIGHT;
	
	UINT16 clr[16]=
    {
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
	0x0000,
    };
	
	for(x = 0; x < XBOUNDS; x+=16){
		for(y = 0; y < YBOUNDS; y+=16){
			plot_bitmap_16(base,x,y,clr,height);
		}
	}
	return;
}

void drawVertical(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length){
	int i;
	for(i = 0; i < length;i++){
		plot_bitmap_16(base,x,y,bitmap,height);
		y = y +16;
	}
	return;
}

void drawHorizontal(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length){
	int i;
	for(i = 0; i < length;i++){
		plot_bitmap_16(base,x,y,bitmap,height);
		x = x +16;
	}
	return;
}

void plot_bitmap_16(UINT16 *base,
		    int x, int y,
		    const UINT16 *bitmap,
		    unsigned int height){
    int i;
    int offset;
	
    offset = (x>>4) + (y*40);
    for(i = 0; i < height; i++){
	*(base + offset + (40*i)) = bitmap[i];
    }
    return;
}
