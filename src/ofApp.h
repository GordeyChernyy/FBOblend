#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
    void circle(ofColor c){
        ofSetColor(c);
        ofCircle(mouseX, mouseY, 20);
    };
		void update();
		void draw();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void drawBrush(ofFbo &fbo);
        int brush = 2;
        int dist_points = 3;
        int num_points = 3;
        int point = 2;
        bool drag = false;
        int layer = 1;
    
    vector<ofVec2f> history;
    ofColor color = ofColor(0);
    int opacity = 50;
    
    ofFbo fbo1;
    ofFbo fbo2;
    
    ofColor global_color;
};
