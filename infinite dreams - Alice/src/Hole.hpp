//
//  Hole.hpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//
#include "ofMain.h"
#include "HoleBox.hpp"

class Hole{
public:
    Hole();
    
    void update(ofVec3f pos, int c);
    void draw();
    
    int timer;
    
    ofVec3f mPos;
    float size;
    float alpha[20];
    
    vector<HoleBox> boxes;
    bool isCreating;
    int num;
};
