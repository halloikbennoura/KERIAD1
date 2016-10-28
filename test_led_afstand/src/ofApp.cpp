#include "ofApp.h"

#define PIN_LED 5
#define PIN_LED2 6
#define PIN_SENSOR 10


void ofApp::setup() {
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    ofSetBackgroundColor(50, 255, 50);
    
    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("/dev/cu.usbmodem411");
    serial.setup("/dev/cu.usbmodem411", 9600);
    
    start = 245;
    eind = 255;
    
    led1 = 245;
    led2 = 255;
}


void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
    
    // print firmware name and version to the console
    ofLog() << "Arduino firmware found: " << arduino.getFirmwareName()
    << " v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
    
    arduino.sendDigitalPinMode(PIN_LED, ARD_OUTPUT);
    arduino.sendDigitalPinMode(PIN_LED2, ARD_OUTPUT);
    arduino.sendDigitalPinMode(PIN_SENSOR, ARD_INPUT);
    
    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    //ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
    ofLogNotice() << "Digital Pin " << pinNum << " value: " << arduino.getDigital(pinNum) << endl;
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
    ofLogNotice() << "Analog Pin " << pinNum << " value: " << arduino.getAnalog(pinNum) << endl;
}


void ofApp::update() {
    arduino.update();
    //    ofLog() << "isArduinoReady" << arduino.isArduinoReady() << endl;
    
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            //byte data is being writen into byteData as int.
            afstand = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "cm: " + ofToString(afstand);
        }
    }
    
    
    
    if(afstand != 0)
    {
        // Standard Pulse-effect
        // als het eind is bereikt van de lerp, worden de waardes omgewisseld.
        if(led1 == eind-1){
            eind = start;
            start = 255;
        }
        
        if(led2 == eind-1){
            eind = start;
            start = 255;
        }
        // lerp gaat van start naar eind over een bepaalde tijd (float)
        led1 = ofLerp(start, eind, 0.01f);
        led2 = ofLerp(start, eind, 0.01f);
    }
    else
    {
        // huidige waarde van de led terug naar 0
        led1 = ofLerp(led1, 0, 0.01f);
        led2 = ofLerp(led2, 0, 0.01f);
    
    }
    
    
    arduino.sendPwm(PIN_LED, led1);
    arduino.sendPwm(PIN_LED2, led2);
}

void ofApp::draw() {
    
    //printing byteData into console.
    cout << "INPUT: " << afstand << " LED 1: " << led1 << " LED 2: " << led2 << endl;

}


//void dragEvent(ofDragInfo dragInfo){}

//void gotMessage(ofMessage msg){}

