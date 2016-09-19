#include "ofApp.h"

void ofApp::setup() {
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);
    
    radius = 40;
    
    color1 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    color2 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    color3 = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));

    
    gui.setup("Instellingen", "settings.xml");
    gui.add(count.set("Count",50, 0, 200));
    gui.add(speedX.set("SpeedX", 20, 0, 200));
    gui.add(speedY.set("SpeedY", 20, 0, 200));
    gui.add(color.set("color", 20, 0, 200));
    
    
}


//--------------------------------------------------

void ofApp::update() {
    if (x <= 0) {
        x = 0;
        speedXball = -speedXball;
    } else if (x >= ofGetWidth()) {
        x = ofGetWidth();
        speedXball = -speedXball;
    }
    
    if (y <= 0) {
        y = 0;
        speedYball = -speedYball;
    } else if (y >= ofGetHeight()) {
        y = ofGetHeight();
        speedYball = -speedYball;
    }
    
    //--------------//
    
    if (x2 <= 0) {
        x2 = 0;
        speedXball = -speedXball;
    } else if (x2 >= ofGetWidth()) {
        x2 = ofGetWidth();
        speedXball = -speedXball;
    }
    
    if (y2 <= 0) {
        y2 = 0;
        speedYball = -speedYball;
    } else if (y2 >= ofGetHeight()) {
        y2 = ofGetHeight();
        speedYball = -speedYball;
    }
 
    //--------------//
    
    if (x3 <= 0) {
        x3 = 0;
        speedX = -speedX;
    } else if (x3 >= ofGetWidth()) {
        x3 = ofGetWidth();
        speedX = -speedX;
    }
    
    if (y3 <= 0) {
        y3 = 0;
        speedY = -speedY;
    } else if (y3 >= ofGetHeight()) {
        y3 = ofGetHeight();
        speedY = -speedY;
    }
    
    x += speedX;
    y += speedY;
    
    x2 += speedX;
    y2 += speedY;
}

//--------------------------------------------------

void ofApp::draw() {
    ofSetColor(ofColor::red);
    ofDrawCircle(x, y, radius);
}

//--------------------------------------------------

void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------

void ofApp::keyReleased(int key){
    if (key == ' ') {
        
    }
}