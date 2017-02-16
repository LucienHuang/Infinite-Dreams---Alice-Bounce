//
//  Clock.hpp
//  11_16_Alice
//
//  Created by Lucien on 2016/11/16.
//
//
#include "ofMain.h"

class Clock{
public:
    Clock();
    
    void update();
    void draw();
    void setForce(int gesture);
    
    ofVec3f cPos[12];
    ofVec3f sPos[12];
    ofVec3f sVel[12];
    ofVec3f gravity[12];
    float a[12];
    float bigRadius;
    int timerMillis;
    int timerSeconds;
    float theta;
    ofVec3f dropPos[12][20];
    ofVec3f dropVel[12][20];
    ofVec3f dropAcc[12][20];
    float dropSize[12][20];
    float alpha[12][20];
    float friction;
    int count;
};
