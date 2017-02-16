//
//  HoleBox.hpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//

#include "ofMain.h"
class HoleBox{
public:
    HoleBox(ofVec3f pos, int c);
    
    void update();
    void draw();

    ofVec3f mPosition;
    ofVec3f mVel;
    ofVec3f mAcc;
    float alpha;
    float size;
    int red, green, blue;
    float timer;
    int timerS;
    int co;
};
