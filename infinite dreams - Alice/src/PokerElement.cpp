//
//  PokerElement.cpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "PokerElement.hpp"

PokerElement::PokerElement(ofVec3f position, int BR, float alpha){
    mPosition = position;
    for(int i = 0; i<10; i++){
        pos[i] = position;
        vel[i] = ofVec3f(ofRandom(-30,30),ofRandom(-30,30),ofRandom(-30,30));
        acc[i] = ofVec3f(0,0,0);
        friction = 0.99;
    }
    mAlpha = alpha;
    if(BR==0){
        col = ofColor(255);
    }else if(BR==1){
        isBlack = true;
    }else if(BR==2){
        isBlack = false;
    }
    size = 15;
    
    
    ofLoadImage(tClub, "club.png");
    ofLoadImage(tDiamond, "diamond.png");
    ofLoadImage(tHeart, "heart.png");
    ofLoadImage(tSpade, "spade.png");
    shader.load("", "shader.frag");
    CS = (int)ofRandom(2);
    
//    rX=ofRandom(45);
//    rY=ofRandom(45);
//    rZ=ofRandom(45);
}

void PokerElement::update(ofVec3f left, ofVec3f right, ofVec3f position){
    timer = ofGetElapsedTimef()-47;
    if(timer<1) mAlpha = 0;
    
    if(timer<26){
        mPosition = position;
        
        if(mAlpha<200){
            mAlpha+=10;
        }
    }else{
        mPosition += 0.05*(ofVec3f(0,0,0)-mPosition);
        if(size>0) size-=0.15;
    }
    
    for(int i = 0; i<15; i++){
        vel[i]*=friction;
        if(timer<33){
        acc[i]=0.1*(mPosition-pos[i]).getNormalized();
        }else{
            acc[i] = (ofVec3f(0,0,0)-pos[i]);
        }
        vel[i]+=acc[i];
        pos[i]+=vel[i];
    }
    
    rX+=0.005;
    rY-=0.005;
    rZ+=0.005;
}

void PokerElement::draw(){
    shader.begin();
    for(int i = 0; i<15; i++){
        ofSetColor(196,0,0,mAlpha-120);
        ofDrawSphere(pos[i], size*0.07);
    }
    
    if(isBlack){
        if(CS==0){
            shader.setUniformTexture("u_tex0", tClub, 0);
            shader.setUniform2f("u_tex0Resolution", tClub.getWidth(), tClub.getHeight());
        }else{
            shader.setUniformTexture("u_tex0", tSpade, 0);
            shader.setUniform2f("u_tex0Resolution", tSpade.getWidth(), tSpade.getHeight());
        }
    }else{
        if(CS==0){
            shader.setUniformTexture("u_tex0", tHeart, 0);
            shader.setUniform2f("u_tex0Resolution", tHeart.getWidth(), tHeart.getHeight());
        }else{
            shader.setUniformTexture("u_tex0", tDiamond, 0);
            shader.setUniform2f("u_tex0Resolution", tDiamond.getWidth(), tDiamond.getHeight());
        }
    }
    ofDrawBox(mPosition, 2*size);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    shader.end();
//    if(isBlack){
//        for(int i = 0; i<20; i++){
//            ofSetColor(196,0,0,mAlpha-120);
//            ofDrawSphere(pos[i], size*0.07);
//        }
//        ofSetColor(255, mAlpha);
//        ofDrawBox(mPosition, 2*size);
//    }else{
//        for(int i = 0; i<20; i++){
//            ofSetColor(255,mAlpha-120);
//            ofDrawSphere(pos[i], size*0.07);
//        }
//        ofSetColor(196,0,0, mAlpha);
//        ofDrawSphere(mPosition, size);
//    }
}
