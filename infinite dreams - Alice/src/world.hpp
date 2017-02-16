//
//  world.hpp
//  example
//
//  Created by Lucien on 2016/11/17.
//
//
#include "ofMain.h"

class World{
public:
    World();
    
    void update();
    void draw();
    
    ofVec3f pos1,pos2;
    ofVec3f vel1,vel2;
    float height1,height2;
    
    int timer;
};
