//
//  HoleBox.cpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//

#include "HoleBox.hpp"

HoleBox::HoleBox(ofVec3f pos, int c)
{
    mPosition = pos;
    co = c;
    if(c==0){
        red = 200;
        green = 255;
        blue = 50;
    }else if(c==1){
        red = 255;
        green = 96;
        blue = 57;
    }else{
        red = 255;
        green = 65;
        blue = 116;
    }
    mVel = ofVec3f(ofRandom(-6,6),ofRandom(-8,0),ofRandom(-6,6));
//    mAcc = ofVec3f(0,ofRandom(0,1.f),0);
    alpha = 255;
    size=ofRandom(8);
    timer = 0;
}

void HoleBox::update()
{
    timerS = ofGetElapsedTimef()-10;
    mAcc = ofVec3f(0,(timerS-15)*ofRandom(0.1f),0);
    mPosition+=mVel;
    mVel+=mAcc;
    size+=0.3;
//    timer = (ofGetElapsedTimeMillis()-20000)/100.f;
    alpha-=3;
    
    if(co ==0){
        if(blue<255){
            blue = 50+10*(timerS-15);
            green = 255-(timerS-15);
            red = 200-5*(timerS-15);
        }
    }else if(co==1){
        if(blue>0){
            green = 96+5*(timerS-15);
            blue = 57-2*(timerS-15);
        }
    }else{
        if(red>0){
            red = 255-4*(timerS-15);
            blue = 116+2*(timerS-15);
            green = 65+9*(timerS-15);
        }
    }
}

void HoleBox::draw()
{
    ofSetColor(red+ofRandom(-40,40),green+ofRandom(-40,40),blue+ofRandom(-40,40), alpha);
    ofDrawBox(mPosition, size);
}
