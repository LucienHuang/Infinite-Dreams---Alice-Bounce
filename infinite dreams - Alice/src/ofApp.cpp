#include "ofApp.h"

//--------------------------------------------------------------


void ofApp::setup(){
    ofBackground(255);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_VERBOSE);
    
	leap.open();
    leap.setupGestures();
    cam.setOrientation(ofPoint(0, 0, 0));
//    cam.rotate(45, -45, -45, -45);
    cam.lookAt(ofPoint(0,0,0));
    music.load("a.mp3");
    music.play();
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    turningAngle = 0;
    
    middle - ofPoint(0,0,0);
    left = ofVec3f(-200,0,0);
    right = ofVec3f(200,0,0);
    left2 = ofVec3f(-1000,0,0);
    right2 = ofVec3f(-1000,0,0);
    left3 = ofVec3f(-200,0,0);
    right3 = ofVec3f(200,0,0);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    timer = ofGetElapsedTimef()-10;
    
	fingersFound.clear();
	
	//here is a simple example of getting the hands and drawing each finger and joint
	//the leap data is delivered in a threaded callback - so it can be easier to work with this copied hand data
	
	//if instead you want to get the data as it comes in then you can inherit ofxLeapMotion and implement the onFrame method.
	//there you can work with the frame data directly.
    
    
    
    //Option 1: Use the simple ofxLeapMotionSimpleHand - this gives you quick access to fingers and palms.
    
    simpleHands = leap.getSimpleHands();
    
    
    if( leap.isFrameNew() && simpleHands.size() ){
        leap.updateGestures();
        int gesture = leap.iGestures;
        cout<<gesture<<endl;
        if(gesture == 4){
            clock.setForce(0);
        }else if(gesture==3){
            clock.setForce(1);
        }
    
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
		leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < simpleHands.size(); i++){
            for (int f=0; f<5; f++) {
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
            }
        }
    }
    
    if(timer<20){
        if(simpleHands.size()){
            if(simpleHands[0].isLeft){
                turningAngle+=1;
                if(turningAngle>540) turningAngle = 0;
                if((simpleHands[0].fingers[THUMB].tip-simpleHands[0].fingers[PINKY].tip).length()<100){
                    cam.reset();
                }else{
                    cam.setOrientation(ofPoint(0, 0, 0));
                    cam.rotate(45, -45, -45, -45);
                    cam.lookAt(ofPoint(0,0,0));
                }
            }
            if(simpleHands.size()>1){
                if(simpleHands[1].isLeft){
                    turningAngle+=1;
                    if(turningAngle>540) turningAngle = 0;
                    if((simpleHands[1].fingers[THUMB].tip-simpleHands[1].fingers[PINKY].tip).length()<100){
                        cam.reset();
                    }else{
                        cam.setOrientation(ofPoint(0, 0, 0));
                        cam.rotate(45, -45, -45, -45);
                        cam.lookAt(ofPoint(0,0,0));
                    }
                }
            }
        }
    }
    
    
    if(timer==16){
        ofBackground(0);
        cam.reset();
    }
    else if(timer==38){
        ofBackground(9, 44, 64);
        red = 9;
        green = 44;
        blue = 64;
    }
    else if(timer>69){
        mi+=0.05;
        if(red<250) red+=mi;
        if(green<250) green+=mi;
        if(blue<250) blue+=mi;
        ofBackground(red, green, blue);
    }
    
    if(timer<17){
        clock.update();
        floor.update();
    }
    
    if(timer<45&&timer>15){        if(simpleHands.size()){
            if(simpleHands[0].isLeft){
                left = simpleHands[0].handPos;
            }else{
                right = simpleHands[0].handPos;
            }
            if(simpleHands.size()>1){
                if(simpleHands[1].isLeft){
                    left = simpleHands[1].handPos;
                }else{
                    right = simpleHands[1].handPos;
                }
            }
    }
        hole[0].update((left+right)/2,0);
        hole[1].update(left,1);
        hole[2].update(right,2);
    }
    
    if(timer>17&&timer<38){
        world.update();
    }
    
    if(timer>37&&timer<66){
        if(simpleHands.size()){
            if(simpleHands[0].isLeft){
                left2 = simpleHands[0].fingers[INDEX].tip;
            }else{
                right2 = simpleHands[0].fingers[INDEX].tip;
            }
            if(simpleHands.size()>1){
                if(simpleHands[1].isLeft){
                    left2 = simpleHands[1].fingers[INDEX].tip;
                }else{
                    right2 = simpleHands[1].fingers[INDEX].tip;
                }
            }
        }
        poker.update(left2, right2);
        hats.angle = 0;
    }
    
    if(timer>67){
        hats.update(left3, right3);
    }
    
    
    
    //Option 2: Work with the leap data / sdk directly - gives you access to more properties than the simple approach
    //uncomment code below and comment the code above to use this approach. You can also inhereit ofxLeapMotion and get the data directly via the onFrame callback.
    /*
     vector <Hand> hands = leap.getLeapHands();
     if( leap.isFrameNew() && hands.size() ){
     
     //leap returns data in mm - lets set a mapping to our world space.
     //you can get back a mapped point by using ofxLeapMotion::getMappedofPoint with the Leap::Vector that tipPosition returns
     leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
     leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
     leap.setMappingZ(-150, 150, -200, 200);
     
     fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
     
     for(int i = 0; i < hands.size(); i++){
     for(int j = 0; j < 5; j++){
     ofPoint pt;
     
     const Finger & finger = hands[i].fingers()[ fingerTypes[j] ];
     
     //here we convert the Leap point to an ofPoint - with mapping of coordinates
     //if you just want the raw point - use ofxLeapMotion::getofPoint
     pt = leap.getMappedofPoint( finger.tipPosition() );
     pt = leap.getMappedofPoint( finger.jointPosition(finger.JOINT_DIP) );
     
     fingersFound.push_back(finger.id());
     }
     }
     }
     */
    
	//IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
	leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
//	
//	ofSetColor(200);
//	ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);
    cam.begin();
    
//	ofPushMatrix();
//    ofRotate(90, 0, 0, 1);
//    ofSetColor(20);
//    ofDrawGridPlane(800, 20, false);
//	ofPopMatrix();
    
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;
        
//        ofSetColor(0, 0, 255);
//        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
//        ofSetColor(255, 255, 0);
//        ofDrawArrow(handPos, handPos + 100*handNormal);
        
        for (int f=0; f<5; f++) {
            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
            
            ofSetColor(0, 150, 255);
            ofDrawBox(tip.x, tip.y, tip.z, 3);
        }
    }
    if(timer<17){
        clock.draw();
        floor.draw();
    }
    
    if(timer<45&&timer>15){
        for(int i = 0; i<3; i++){
            hole[i].draw();
        }
    }
    
    if(timer>17&&timer<38){
        world.draw();
    }
    
    if(timer>37&&timer<69){
        poker.draw();
    }
    
    if(timer>67){
        hats.draw();
    }
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cam.setOrientation(ofPoint(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}
