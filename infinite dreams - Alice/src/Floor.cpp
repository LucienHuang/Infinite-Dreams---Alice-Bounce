//
//  Floor.cpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//

#include "Floor.hpp"

Floor::Floor(){
    size = 0;
    angle=90;
    floatY = 500.f;
    alpha = 0;
}

void Floor::update(){
    timer = ofGetElapsedTimef()-10;
    
    if(timer>13){
        size+=100;
        if(floatY>0) floatY--;
        angle+=0.5f;
    }else{
        alpha+=0.4f;
        size=timer*200;
    }
}

void Floor::draw(){
    ofSetColor(255-alpha);
    ofRotateX(angle);
    ofDrawPlane(0, 0, floatY, size, size);
}
