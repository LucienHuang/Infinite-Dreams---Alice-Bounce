//
//  Hole.cpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//

#include "Hole.hpp"

Hole::Hole()
{
    isCreating = false;
    num = 7;
    size = 500;
}

void Hole::update(ofVec3f pos, int c)
{
    mPos = pos;
    timer = ofGetElapsedTimef()-10;
    if(timer>35){
        isCreating = false;
    }else if(timer>16){
        isCreating = true;
    }
    
    if(isCreating){
        for(int i = 0; i<num; i++){
            HoleBox tempBox(pos, c);
            boxes.push_back(tempBox);
        }
    }
    for(int i = 0; i<boxes.size(); i++){
        boxes[i].update();
        if(boxes[i].alpha<0){
            boxes.erase(boxes.begin()+i);
        }
    }
}

void Hole::draw()
{
//    if(timer>0){
//    ofSetSphereResolution(1000);
//    ofSetColor(197, 255, 246, timer*10);
//        ofDrawSphere(mPos, timer*300);}
    for(int i = 0; i<boxes.size(); i++){
        boxes[i].draw();
    }
}
