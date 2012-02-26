
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "smImage.h"
#include  "smObject.h"


class testApp : public ofBaseApp{
	
public:

	int mouseX;
	int mouseY;
	
	int state;

	int label;
	int x, y;
	
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	bool seedFill(int x, int y, int label);

	
	smImage * img1; //notice this is a pointer!!!
	smImage * labelImg;

	vector<smObject*>  objectSet;    // vector array of object pointers...
	
	int left;
	int right;
	int top;
	int bottom;
	
};

#endif

