#include "testApp.h"

void testApp::setup(){
	
	//initiate a new image
	//put in the whole directory when you are loading files!!! 
	img1 = new smImage ("/Users/yinliu/Downloads/SM12_flood_fill_images_v2/flood_fill_test_01.raw",320,240);
	img2 = new smImage ("/Users/yinliu/Downloads/SM12_flood_fill_images_v2/flood_fill_test_02.raw",320,240);
	labelImg = new smImage(320,240);
	label= 100;
	curImg = new smImage (320,240);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
	switch (state) {
		case 1:
			curImg=img1;
			break;
			
		case 2:
			curImg= img2;
		default:
			break;
	}
	
	for (int x=0; x<curImg->width; x++) {
		for (int y=0; y<curImg->height; y++) {
			if (curImg->getPixel(x,y)!=0) {
			   if(seedFill(x,y,label)){
				  label+=30;	
			}
		}
	}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	switch (state) {
		case 1:
			curImg=img1;
			break;
		case 2:
			curImg = img2;
		default:
			break;
	}
		
	curImg->draw(50.0,50.0);
	labelImg->draw(450.0,50.0);
	
}


bool testApp::seedFill(int x, int y, int label) {
	
	/*switch (state) {
		case 1:
			curImg=img1;
			break;
		case 2:
			curImg =img2;
			break;
		default:
			break;
	}
	*/
	if (curImg->getPixel(x,y)==0) {
		return false;
	}
	
	if (labelImg->getPixel(x,y)!=0) {
		return false;
	}
	
	labelImg->setPixel(x,y,label);
	
	if(x>1 && y>1 && y<curImg->width-1 && x<curImg->height-1){
	seedFill(x,y-1,label); //north
	seedFill(x+1, y,label); //east
	seedFill(x,y+1,label); //south
	seedFill(x-1,y,label); //west
	}
	
	return true;
	
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key==49) {
		state =1;
	}
	if (key==50) {
		state =2;
	}
}

 
 
	
	
	
	
	
	
	
