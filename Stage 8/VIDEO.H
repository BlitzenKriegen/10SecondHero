/*
Authors: Enrik R and Kiril S

This is the .H file for the .s files used for Physbase() and Setscreen()
 */
#ifndef VIDEO_H
#define VIDEO_H

#include "const.h"

/*
Same as Physbase(), returns the screen/video base

*/
UINT16 *getVideoBase();

/*
Same as Setscreen(), sets screen base to given address.
 
*/
void setVideoBase(UINT16 *base);

#endif
