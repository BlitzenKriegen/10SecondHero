#ifndef RASTER_H
#define RASTER_H

typedef unsigned char UINT8;  /* for 8x8 bitmaps */
typedef unsigned int  UINT16; /* for 16x16 bitmaps*/
typedef unsigned long UINT32; /* for 32x32 bitmaps */


/* plots a 16 pixel x 16 pixel bitmap  to the frame buffer*/
void plot_bitmap_16(UINT16 *base,
		    int x, int y,
		    const UINT16 *bitmap,
		    unsigned int height);

/* plots a horizontal line to the frame buffer*/
void drawHorizontal(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length);

/* plots a vertical line to the frame buffer*/
void drawVertical(UINT16 *base,
			  int x, int y,
			  const UINT16 *bitmap,
			  unsigned int height,
			  int length);
			  
void drawPixel(UINT8 *base, int x,
			   int y);

/* "clears" the frame buffer by setting all the pixels to white*/
void clearScreen();

#endif
