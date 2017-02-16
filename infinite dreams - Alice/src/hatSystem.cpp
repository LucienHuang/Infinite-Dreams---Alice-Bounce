//
//  hatSystem.cpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "hatSystem.hpp"

HatSystem::HatSystem(){
    for(int i = 0; i<1000; i++){
        pos[i] = ofVec3f(0,0,0);
        vel[i] = ofVec3f(sin(ofRandom(TWO_PI))*ofRandom(-50,50),sin(ofRandom(TWO_PI))*ofRandom(-50,50),sin(ofRandom(TWO_PI))*ofRandom(-60,60));
        MaxAlpha[i] = ofRandom(200,230);
        alpha[i] = 0;
        size[i] = ofRandom(5,22);
        count = 0;
    }
    
    
    friction = 0.99;
    angle = 0;
}

void HatSystem::update(ofVec3f l, ofVec3f r){
    for(int i = 0; i<1000; i++){
        vel[i]*=friction;
        pos[i]+=vel[i];
        alpha[i] = ofMap(vel[i].length(), 0, 100, MaxAlpha[i], 30);
        if(vel[i].length()<0.1) count++;
    }
    
    angle+=0.03;
}

void HatSystem::draw(){
    ofRotateZ(angle);
    ofRotateY(angle);
    
    for(int i = 0; i<1000; i++){
        ofSetColor(255, alpha[i]);
        ofDrawSphere(pos[i], size[i]);
    }
}
