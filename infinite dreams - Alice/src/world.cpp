//
//  world.cpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "world.hpp"

World::World(){
    pos1 = ofVec3f(0,-2000,0);
    vel1 = ofVec3f(0,60,0);
    height1 = ofRandom(5,20);
    height2 = 4000;
    vel2 = ofVec3f(0,40,0);

}

void World::update(){
    timer = ofGetElapsedTimef()-10;
    
    if(timer==24){
        pos2.y = -10000;
    }
    
    if(timer>18&&timer<30){
        pos1+=vel1;
        if(pos1.y>3000){
//            height1 = ofRandom(5,50);
            pos1.y = -2000;
            vel1.y+=20;
        }
    }
    
    if(timer>24){
        if(pos2.y<0){
            pos2+=vel2;
        }else{
            pos2 = ofVec3f(0,0,0);
        }
    }
    
}

void World::draw(){
    if(timer<30){
        ofSetColor(ofRandom(0,255), 150);
        ofDrawBox(pos1, 2000, height1, 2000);
    }
    if(timer>24){
        ofSetColor(9, 44, 64);
        ofDrawBox(pos2, 2000, height2, 2000);
    }
}
