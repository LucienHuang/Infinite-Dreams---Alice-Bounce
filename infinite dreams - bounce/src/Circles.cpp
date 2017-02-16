//
//  Circles.cpp
//  example
//
//  Created by Lucien on 2016/12/5.
//
//

#include "Circles.hpp"

Circles::Circles(){
    friction = 0.7;
    red = 255;
    green = 0;
    blue = 0;
    theta = 0;
}

void Circles::update(ofVec3f fingerTip){
    theta+=(PI/360.f);
    finger.x = ofGetWindowWidth()/2+fingerTip.x+ofRandom(-10,10);
    finger.y = ofGetWindowHeight()/2-fingerTip.y+ofRandom(-10,10);
    
    if(red==255&&green<255&&blue==0){
        green+=5;
    }else if(red>0&&green==255&&blue==0){
        red-=5;
    }else if(red==0&&green==255&&blue<255){
        blue+=5;
    }else if(red==0&&green>0&&blue==255){
        green-=5;
    }else if(red<255&&green==0&&blue==255){
        red+=5;
    }else if(red==255&&green==0&&blue>0){
        blue-=5;
    }
    
    pos.push_back(finger);
    vel.push_back(ofVec2f(0,0));
    acc.push_back(ofVec2f(0,0));
    size.push_back(0);
    growth.push_back(1);
    col.push_back(ofColor(red,green,blue));
    brightness.push_back(150);
    
    for(int i = 0 ;i<pos.size(); i++){
        acc[i] = (finger-pos[i]).getNormalized();
        vel[i]+=acc[i];
//        vel[i]*=friction;
        pos[i]+=vel[i];
        growth[i]+=0.05;
        size[i]+=growth[i];
//        brightness[i] = ofMap(size[i], 30, ofGetWindowWidth(), 150, -150);
//        if(size[i]>ofGetWindowWidth()){
//            pos.erase(pos.begin()+i);
//        }
    }
}

void Circles::draw(){
    ofSetCircleResolution(200);
    for(int i = pos.size();i>0; i--){
        if(size[i]<ofGetWindowWidth()/1.5){
            ofSetColor(col[i]);
            ofDrawCircle(pos[i], size[i]);
//            ofSetRectMode(OF_RECTMODE_CENTER);
//            ofRotate(theta);
//            ofDrawRectangle(pos[i], size[i], size[i]);
        }
    }
}
