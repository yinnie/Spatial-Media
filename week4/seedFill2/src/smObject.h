/*
 *  smObject.h
 *  seedFill2
 *
 *  Created by Yin Liu on 2/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _SM_OBJECT
#define _SM_OBJECT
#include "smImage.h"


class smObject 
{
	
public:
	
	smObject (int _ID);
	
	int ID;
	
	void acceptPixel(int xPos, int yPos);
	int pixelCount;
	int midPointX;
	int midPointY;
	
	float top, left, bottom, right;
	
	
};


#endif