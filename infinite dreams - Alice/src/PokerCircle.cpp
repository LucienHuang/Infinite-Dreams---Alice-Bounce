//
//  PokerCircle.cpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "PokerCircle.hpp"

PokerCircle::PokerCircle(ofVec3f position, int isBlack){
    mPosition = position;
    timer = ofGetElapsedTimeMillis();
    count = (int)ofRandom(6, 18);
    radius = count*10;
    theta = TWO_PI/count;
    BR = isBlack;
    beta = 0;
    speed = ofRandom(PI/120);
    move1 = ofRandom(-0.5,0.5);
    move2 = ofRandom(-0.5,0.5);
    move3 = ofRandom(-5,5);
    for(int i = 0; i<count; i++){
        PokerElement temp(ofVec3f(mPosition.x+radius*sin(i*theta),mPosition.y+radius*cos(i*theta),0),BR,-count*i*20);
        elements.push_back(temp);
    }
    
}

void PokerCircle::update(ofVec3f left, ofVec3f right){
    x = move1*(left.x-right.x);
    y = move2*(left.y-right.y);
    z = move3*(left.z-right.z);
    for(int i = 0; i<elements.size(); i++){
        elements[i].update(left, right, ofVec3f(mPosition.x+radius*sin(i*theta+beta)+x,mPosition.y+radius*cos(i*theta+beta)+y,z));
    }
    beta+=speed;
    radius = count*10+20*sin(beta*5);
}

void PokerCircle::draw(){
    for(int i = 0; i<elements.size(); i++){
        elements[i].draw();
    }
}
