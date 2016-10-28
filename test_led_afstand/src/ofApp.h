#pragma once

#include "ofMain.h"
#include "ofEvents.h"

class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    
    void update();
    
    void draw();
    
    //void windowResized(int w, int h);
    
    //void dragEvent(ofDragInfo dragInfo);
    
    //void gotMessage(ofMessage msg);
    
    //New serial object.
    ofSerial serial;
    
    string msg;
    
    int start, eind;
    int led1;
    int led2;
    int led1_brightness;
    int led2_brightness;
    int afstand;
    
private:
    ofArduino arduino;
    
    void setupArduino(const int& version);
    
    void digitalPinChanged(const int& pinNum);
    
    void analogPinChanged(const int& pinNum);
    
};
