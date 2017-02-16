//
//  poker.cpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "poker.hpp"

Poker::Poker(){
    create = true;
    for(int i = 0; i<20; i++){
        if(i%2==0){
            PokerCircle temp(ofVec3f(ofRandom(-400, 400),ofRandom(-400, 400),0),1);
            circles.push_back(temp);
        }else{
            PokerCircle temp(ofVec3f(ofRandom(-400, 400),ofRandom(-400, 400),0),2);
            circles.push_back(temp);
        }
    }
}

void Poker::update(ofVec3f left, ofVec3f right){
    timer = ofGetElapsedTimef()-47;
    
    for(int i = 0; i<circles.size(); i++){
        if(timer>i/2.f){
        circles[i].update(left, right);
        }
    }

}

void Poker::draw(){
    for(int i = 0; i<circles.size(); i++){
        if(timer>i/2.f){
        circles[i].draw();
        }
    }
}
