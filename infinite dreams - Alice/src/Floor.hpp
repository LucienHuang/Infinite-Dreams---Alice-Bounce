//
//  Floor.hpp
//  example
//
//  Created by Lucien on 2016/11/16.
//
//

#include "ofMain.h"

class Floor{
public:
    Floor();
    
    void update();
    void draw();
    int timer;
    int size;
    float angle;
    float floatY;
    float alpha;
};
