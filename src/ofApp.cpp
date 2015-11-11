#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofDisableTextureEdgeHack();
//    ofEnableTextureEdgeHack();

    fbo1.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo1.begin();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    fbo1.end();
    
    fbo2.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    fbo2.begin();
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    fbo2.end();
    ofBackground(255, 255, 255, 255);
    
    global_color = ofColor(255,0,255,255);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    ofSetColor(255, 255);
    fbo1.draw(0,0);
    ofSetColor(255, 255);
    fbo2.draw(0,0);
    glDisable(GL_BLEND);
}
void ofApp::mouseDragged(int x, int y, int button){
    switch (layer) {
        case 1:
            drawBrush(fbo1);
            break;
        case 2:
            drawBrush(fbo2);
            break;
    }
}
void ofApp::drawBrush(ofFbo &fbo){
    ofVec2f m(mouseX, mouseY);
    history.push_back(m);
    for(int i=0; i< history.size(); i++){
        ofVec2f h = history[i];
        if (m.match(h, ofRandom(3, 200))){
            fbo.begin();
            glEnable(GL_BLEND);
            glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
                    ofNoFill();
                    ofSetColor(color, 25);
                    ofSetLineWidth(1.53);
                    ofLine(h.x, h.y, m.x, m.y);
            glDisable(GL_BLEND);
            fbo.end();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key ==' ') {
        layer == 1? layer = 2: layer = 1;
    }
    if (key == '1') color = ofColor(255, 255, 255);
    if (key == '2') color = ofColor(0, 0, 0);
    if (key == '3') color = ofColor(255, 0, 0);
    if (key == '4') color = ofColor(0, 255, 0);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    history.clear();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
