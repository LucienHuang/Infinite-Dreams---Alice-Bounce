//
//  PokerElement.hpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "ofMain.h"

class PokerElement{
public:
    PokerElement(ofVec3f position, int BR, float alpha);
    
    void update(ofVec3f left, ofVec3f right, ofVec3f position);
    void draw();
    
    int timer;
    int startTime;
    bool isBlack;
    ofVec3f mPosition;
    ofColor col;
    float mAlpha;
    ofVec3f pos[15];
    ofVec3f vel[15];
    ofVec3f acc[15];
    float friction;
    float size;
    int CS;
    
    ofShader shader;
    ofTexture tClub, tDiamond, tHeart, tSpade;
    
    float rX,rY, rZ;
};
