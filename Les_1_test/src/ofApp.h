#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp {
    
public:
    void setup();
    
    void update();
    
    void draw();
    
    void keyPressed(int key);
    
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxPanel gui;
    ofParameter<int> count;
    ofParameter<float> speedX;
    ofParameter<float> speedY;
    ofParameter<int> color;

    
private:
    float x;
    float x2;
    float x3;
    
    float y;
    float y2;
    float y3;
    
    float speedXball;
    float speedYball;
    int radius;
    ofColor color1;
    ofColor color2;
    ofColor color3;
    
    

};