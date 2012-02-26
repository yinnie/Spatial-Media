#include "smImage.h"

//--------------------------------------------------------------


smImage :: smImage (const char* fileName, int W, int H) 
{
	//set the image width and height
	width = W;
	height = H;
	
    //load in the image data from the file 
	//"r" is opening for reading...attaching "b" to the end opens the file as a binary file
	//otherwise it is opened as a text file...since we are dealing with raw file here..we need to open as binary file
	FILE * F = fopen(fileName, "rb");
	
	if (F==NULL)
    {
		printf("ERROR: can't find file %s\n", fileName);
		//%s means printing out a string
		exit(0);  //???  in reference it says exit(0) is success??
	}
	else {
		//allocate memory for the image
		//is this like initiating an array with the type "unsigned char"??
		imageData = new unsigned char [width*height];
		
		fread(imageData, 1, width*height, F);
		//fread function reads a block of data from a file stream
		fclose(F);
	}

}

smImage :: smImage (int W, int H)
{
	//set the image width and height
	width = W;
	height = H;
	
	imageData = new unsigned char [width*height];
	memset(imageData, 0, width*height);  //setting all pixels to black
}


//--------------------------------------------------------------
int smImage::getPixel(int x, int y){

	
	//we use int becoz it is a bigger cup in case we overflow our char cup
	//we are basically getting the imageData at that point in the image
	//so basically to say how do i go from knowing x and y to the 1D array data we have
	int index = x+y*width;
	//we need to exclude cases where x and y are out of our range of things
	if (index <0 || index >= width*height) {
		printf("ERROR :  pixel out of range");
		return 0; //return 0 just means exit???? 
	}
	return imageData[index];  //imageData is just an array

}

//--------------------------------------------------------------
void smImage:: setPixel(int x, int y, int grayValue) {

	
	//changing the data 
	int index = x+y*width;
	if (index <0 || index >= width*height) {
		printf("ERROR :  pixel out of range");
		//return 0;
	}
	imageData[index] = grayValue;
}

void smImage:: draw(float cornerX, float cornerY ) 
{
	// this is an inefficent, but simple mode of drawing an image
    // we draw one rectangle for every pixel
    // use the fastDraw() method if you want something faster
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			//the only thing that we are giving the rectangles is the colour information of the original image
			//where do we get this data? this data is in the imageData[] array...
			//we can do imageData[] but we already defined this into another function which is getPixels[]
			//this saves us from doing the for loop again and again
			int gray= getPixel(x,y);
			ofSetColor(gray, gray, gray);
			ofRect((cornerX+x*1), (cornerY+y*1), 1, 1); //if you dont time x and y by 5 you will overlap things...right now..you are expanding the image 5*5 times bigger
			
		}
	}
}

void smImage:: fastDraw() 
{
	/*
	// replace the image data int the texture
	imageAsTexture ->replace (imageData);
	//draw the texture
	
	*/
}
	

	
	
void smImage:: invert() {
	
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			int grayInverted = 255 - getPixel(x,y);
			ofSetColor(grayInverted, grayInverted, grayInverted);
			ofRect(x*5, y*5, 5, 5); //if you dont time x and y by 5 you will overlap things...right now..you are expanding the image 5*5 times bigger
			
		}
	}
}

void smImage:: flipVertical() {
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			int grayFlipVertical = getPixel(x, (height-y));
			ofSetColor(grayFlipVertical, grayFlipVertical, grayFlipVertical);
			ofRect(x*5, y*5, 5, 5); //if you dont time x and y by 5 you will overlap things...right now..you are expanding the image 5*5 times bigger
			
		}
	}
}

void smImage:: blackWhite() {
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			if (getPixel(x,y) > 119) {
				setPixel(x, y, 255);
			}
			else if (getPixel(x, y)< 119) {
				setPixel(x, y, 0);
			}
			int grayBW = getPixel(x, y);
		    ofSetColor(grayBW,grayBW,grayBW);
			ofRect(x*5, y*5, 5, 5); //if you dont time x and y by 5 you will overlap things...right now..you are expanding the image 5*5 times bigger
			
		}
	}
}

void smImage:: threshold(int T) {
    
	//int T = T_;
	
	for (int x=0; x<width; x++) {
		for (int y=0; y<height; y++) {
			//in order to make the image change with mouse movement
			//it needs to take the original image data not the resulting one from the previous change
						
			int grayValue = getPixel(x,y);
			if (grayValue > T) {
				ofSetColor(255, 255, 255);
			}
			else if (grayValue< T) {
				ofSetColor(0, 0, 0);
			}
			
			ofRect(x*5, y*5, 5, 5); //if you dont time x and y by 5 you will overlap things...right now..you are expanding the image 5*5 times bigger
			
		}
	}
}


void smImage:: edgeDetect(int E_) {	
	int E = E_;
	for (int x=0; x<(width-1); x++) {
		for (int y=0; y<(height-1); y++) {
			float diff = getPixel(x, y) - getPixel(x+1, y+1);
			if (diff>E) {
				ofSetColor(255, 255, 255);
			}
			else if (diff <= E) {
				ofSetColor(0, 0, 0);
			}
			
	
			ofRect(x*5, y*5, 5, 5);
		}
	}
	
}

	
	
