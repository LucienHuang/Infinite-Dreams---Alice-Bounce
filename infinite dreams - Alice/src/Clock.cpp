//
//  Clock.cpp
//  11_16_Alice
//
//  Created by Lucien on 2016/11/16.
//
//

#include "Clock.hpp"

Clock::Clock()
{
    bigRadius = 400;
    for(int i = 0; i<12; i++){
        cPos[i] = ofVec3f(bigRadius*sin(i*PI/6.f),bigRadius*cos(i*PI/6.f),0);
        sPos[i] = ofVec3f(0,30*i,0);
        sVel[i] = ofVec3f(0,0,0);
        gravity[i] = ofVec3f(0,ofRandom(-0.5f,0.f),0);
        for(int j = 0; j<20; j++){
            dropPos[i][j] = ofVec3f(bigRadius*sin(i*PI/6.f),bigRadius*cos(i*PI/6.f),0);
            dropVel[i][j] = ofVec3f(ofRandom(-10,10),ofRandom(1,20),ofRandom(-10,10));
            dropSize[i][j] = ofRandom(3,10);
            alpha[i][j] = 255;
            dropAcc[i][j] = ofVec3f(ofRandom(-3, 0),ofRandom(0,3),0);
        }
        a[i] = 255;
    }
    friction = 0.999;
    theta = 0;
}

void Clock::update()
{
    timerMillis = ofGetElapsedTimeMillis();
    timerSeconds = ofGetElapsedTimef()-10;
    theta=timerSeconds*PI/30.f;
    for(int i =0; i<12; i++){
        if(timerSeconds<15){
            sPos[i] = ofVec3f(30*i*sin(theta),30*i*cos(theta),0);}else{
                sPos[i]+=sVel[i];
                sVel[i]*friction;
                sVel[i]+=gravity[i];
                if(sPos[i].y<-500){
                    sVel[i].y = -sVel[i].y;
                }
                a[i]-=1.f+ofRandom(0.5f);
            }
        for(int j = 0; j<20; j++){
            if(timerSeconds>i+1){
                dropPos[i][j]+=dropVel[i][j];
                dropVel[i][j]+=ofVec3f(0,-1.f,0);
                dropVel[i][j]*=friction;
                if(dropPos[i][j].y<-500){
                    dropVel[i][j].y = -dropVel[i][j].y;
                }
                alpha[i][j]-=0.2f+ofRandom(0.5f);
            }
        }
    }
}

void Clock::draw()
{
    for(int i = 0; i<12; i++){
        ofSetColor(170-i*5, 0, 0);
        if(timerSeconds<=i+1){
            ofDrawSphere(cPos[i], 30);
        }else{
            for(int j = 0; j<20; j++){
                ofSetColor(170-i*5-(255-alpha[i][j]), 0, 0);
                if(alpha[i][j]>0){
                    ofDrawSphere(dropPos[i][j], dropSize[i][j]);}
            }
        }
        ofSetColor(60-(255-a[i]), 60-(255-a[i]), 60-(255-a[i]));
        if(a[i]>0){
            ofDrawBox(sPos[i], 30-i*2);}
    }
}

void Clock::setForce(int gesture){
    for(int i = 0; i<12; i++){
        for(int j = 0; j<20; j++){
            if(timerSeconds>i+1){
                if(gesture==0){
                    dropVel[i][j]+=dropAcc[i][j];
                }else if(gesture==1){
                    dropVel[i][j]-=dropAcc[i][j];
                }
            }
        }
    }
}
