//
//  hatSystem.hpp
//  example
//
//  Created by Lucien on 2016/11/27.
//
//

#include "ofMain.h"
#include "ofMath.h"

class HatSystem{
public:
    HatSystem();
    void update(ofVec3f l, ofVec3f r);
    void draw();
    
    ofVec3f pos[1000];
    ofVec3f vel[1000];
    float friction;
    float angle;
    float alpha[1000];
    float MaxAlpha[1000];
    float size[1000];
    
    int count;
};
