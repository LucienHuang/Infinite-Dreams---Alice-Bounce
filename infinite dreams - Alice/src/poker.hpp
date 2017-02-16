//
//  poker.hpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//
#include "ofMain.h"
#include "PokerCircle.hpp"

class Poker{
public:
    Poker();
    
    void update(ofVec3f left, ofVec3f rights);
    void draw();
    
    int timer;
    bool create;
    int lastTime;
    
    vector<PokerCircle> circles;
//    PokerCircle circles2[30];
};
