#pragma once

#include "ofMain.h"
#include "ofxLeapMotion2.h"
#include "Clock.hpp"
#include "Floor.hpp"
#include "Hole.hpp"
#include "world.hpp"
#include "poker.hpp"
#include "hatSystem.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
	
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void exit();
    
    ofSoundPlayer music;
	ofxLeapMotion leap;
    Listener leapListener;
	vector <ofxLeapMotionSimpleHand> simpleHands;
    
	vector <int> fingersFound;
	ofEasyCam cam;
    
    Clock clock;
    Floor floor;
    Hole hole[3];
    World world;
    Poker poker;
    HatSystem hats;
    int timer;
    
    float turningAngle;
    ofPoint middle;
    ofVec3f left, right;
    ofVec3f left2, right2;
    ofVec3f left3, right3;
    
    float mi = 0;
    float red, green, blue;
    
};
