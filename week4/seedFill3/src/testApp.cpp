#include "testApp.h"

void testApp::setup(){
	
	//initiate a new image
	//put in the whole directory when you are loading files!!! 
	img1 = new smImage ("/Users/yinliu/Downloads/SM12_flood_fill_images_v2/flood_fill_test_03.raw",320,240);
	labelImg = new smImage(320,240);
	label= 100;
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int x=0; x<img1->width; x++) {
		for (int y=0; y<img1->height; y++) {
			if (img1->getPixel(x,y)!=0) {
			   if(seedFill(x,y,label)){
				  label+=30;	
			}
		}
	}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
		
	img1->draw(50.0,50.0);
	labelImg->draw(450.0,50.0);
	
}


bool testApp::seedFill(int x, int y, int label) {
	if (img1->getPixel(x,y)==0) {
		return false;
	}
	
	if (labelImg->getPixel(x,y)!=0) {
		return false;
	}
	
	labelImg->setPixel(x,y,label);
	
	if(x>1 && y>1 && y<img1->width-1 && x<img1->height-1){
	seedFill(x,y-1,label); //north
	seedFill(x+1, y,label); //east
	seedFill(x,y+1,label); //south
	seedFill(x-1,y,label); //west
	}
	
	return true;
	
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
	}

 
 
	
	
	
	
	
	
	
