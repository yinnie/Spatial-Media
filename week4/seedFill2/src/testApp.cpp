#include "testApp.h"

void testApp::setup(){
	
	//initiate a new image
	//put in the whole directory when you are loading files!!! 
	img1 = new smImage ("/Users/yinliu/Downloads/SM12_flood_fill_images_v2/flood_fill_test_01.raw",320,240);
	labelImg = new smImage(320,240);
	label= 100;  //label starts at 0 so that it is easier to identify number of objects later
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	//floodfill our image
	for (int x=0; x<img1->width; x++) 
	{
		for (int y=0; y<img1->height; y++) 
		{
			if (img1->getPixel(x,y)!=0) 
			{
			   if(seedFill(x,y,label))
			   {
				  label+=1;	
			   }
			}
		}
	}
	//printf("number of shapes : ??? ");
	
	
	//each label represents one object...we are making object 0 just so that later the "found" object will be nubmered ..1..2.3..
	for (int i=0; i<label; i++) 
	{
		smObject* OBJ = new smObject (i);
		objectSet.push_back(OBJ);  //adding a new object to our dynamic array
		
	}
	
	
	//put pixels into object(buckets) 
	for (int i=0; i<320; i++) 
	{
		for (int j=0; j<240; j++) 
		{
			int V = labelImg->getPixel(i,j); //get the label
			objectSet[V]->acceptPixel(i,j); //lable now becomes index of the array
			//amplification ..make everything brighter.
			labelImg->setPixel(i,j, V);
		}
	}
	/*
	
	//go through shapes..saying .size() is safer than say label
	for(int i=0; i<label; i++)   
	{   
		printf("%d\n", objectSet[i]->pixelCount);
		//center of mass
		int midPointx = objectSet[i]->midPointX/objectSet[i]->pixelCount;
	    int midPointy = objectSet[i]->midPointY/objectSet[i]->pixelCount;
	    labelImg ->setPixel(midPointx, midPointy, 255);
		
	}
	*/ 
		
}

//--------------------------------------------------------------
void testApp::draw(){
		
	img1->draw(50.0,50.0);
	labelImg->draw(450.0,50.0);
	
	for(int i=0; i<objectSet.size(); i++)   //saying .size() is safer than say label
	{  
		left= objectSet[i]->left;
		right= objectSet[i]->right;
		top= objectSet[i]->top;
		bottom= objectSet[i]->bottom;
	
		ofEnableAlphaBlending();
		ofNoFill();
		ofSetColor(255,0,0);
		ofRect(left+50, top+50, right-left, bottom-top);			
	}
			
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

 
 
	
	
	
	
	
	
	
