//
//  PokerCircle.hpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//

#include "ofMain.h"
#include "PokerElement.hpp"

class PokerCircle{
    public:
    PokerCircle(ofVec3f position, int isBlack);
    
    void update(ofVec3f left, ofVec3f right);
    void draw();
    
    vector<PokerElement> elements;
    
    ofVec3f mPosition;
    int timer;
    int passedTime;
    int count;
    int radius;
    int BR;
    float theta;
    float beta;
    float speed;
    float move1, move2, move3;
    float x,y,z;
};
