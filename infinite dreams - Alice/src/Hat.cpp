//
//  Hat.cpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "Hat.hpp"

Hat::Hat(ofVec3f pos, int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
    mPos = pos;
    lifeSpan = 1500;
    size = 15;
    alpha = 255;
}

void Hat::update(ofVec3f hand){
    lifeSpan--;
    size = ofMap(lifeSpan, 0, 1500, 0, 15);
    if(lifeSpan<400){
        alpha = ofRandom(0,255);
    }
}

void Hat::draw(){
    ofSetColor(r, g, b, alpha);
    ofDrawSphere(mPos, size+ofRandom(-1,1));
}
