
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "smImage.h"



class testApp : public ofBaseApp{
	
public:

	int x;
	int y;
	int mouseX;
	int mouseY;
	
	int state;

	int label;
	
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	bool seedFill(int x, int y, int label);

	
	smImage * img1; //notice this is a pointer!!!
	smImage * img2;
    smImage * img3;
	smImage * labelImg;
	smImage * curImg;

	
};

#endif

