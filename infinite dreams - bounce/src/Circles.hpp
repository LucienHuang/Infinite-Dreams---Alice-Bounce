//
//  Circles.hpp
//  example
//
//  Created by Lucien on 2016/12/5.
//
//

#include "ofMain.h"
#include "ofMath.h"

class Circles{
public:
    Circles();
    void update(ofVec3f fingerTip);
    void draw();
    
    
    ofVec2f finger;
    vector<ofVec2f> pos;
    vector<ofVec2f> vel;
    vector<ofVec2f> acc;
    vector<float> size;
    vector<ofColor> col;
    vector<float> growth;
    vector<float> brightness;
//    float growth;
    float friction;
    int red, green, blue;
    float theta;
};
