/*
 *  smObject.cpp
 *  seedFill2
 *
 *  Created by Yin Liu on 2/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "smObject.h"

smObject :: smObject (int _ID) 
{

	ID = _ID;
	pixelCount=0;
	
	midPointX=0;
	midPointY=0;
	
	right =0.0;
	bottom =240.0;
	top =0.0;
	left = 320.0;
}

void smObject :: acceptPixel (int xPos, int yPos)
{
    pixelCount++;
		
	//modify the pixels as they come in
	midPointX+=xPos;
	midPointY+=yPos;
	
	//everytime a pixel comes in...we maake them..min or maximum
	if (xPos<left) {
		left =xPos;
	}
	if (xPos>right) {
		right=xPos;
	}
	if (yPos>top) {
		top =yPos;
	}
	if (yPos<bottom) {
		bottom =yPos;
	}
	

}