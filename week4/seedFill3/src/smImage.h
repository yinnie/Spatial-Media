#include "ofMain.h"

#ifndef _SM_IMAGE
#define _SM_IMAGE

class smImage 
{
	public : 
   //the image constructor
	//empty constructor
	smImage();
	smImage(int W, int H);
    //how to construct an image from a raw file
    smImage(const char* fileName, int W, int H);
	
	//what are the methods to draw this image on screen
	void draw(); //drawing one rectangle for each pixel
	void fastDraw();
	void draw(float cornerX, float cornerY);
	
	
	//methods to get and set pixels
	int getPixel(int x, int y);  //CAUTION type is int!!!
	void setPixel(int x, int y, int grayValue);
	void reset();
	
	int T; //threshold value for threshold method
	int E; // threshold value for edge detect

	
	int grayBW;
	int grayT;
	int grayE;
	
	float cornerX;
	float cornerY;
	
	void invert();
	void flipVertical();
	void blackWhite();
	void threshold(int T);
	void edgeDetect(int E);
	
	
	
	//variables
	int width, height;
	unsigned char * imageData; //this is a pointer to the object imageData and it is the original data
		
	ofTexture imageAsTexture;
	
};

#endif

    