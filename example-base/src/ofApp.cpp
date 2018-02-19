#include "ofApp.h"

//#define USE_RGB
//#define USE_IR

#include "ofxNI2.h"

ofxNI2::Device *device;
#ifdef USE_IR
ofxNI2::IrStream ir;
#endif
#ifdef USE_RGB
ofxNI2::ColorStream color;
#endif
ofxNI2::DepthStream depth;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    device = new ofxNI2::Device;
    device->setup();
    
    if (depth.setup(*device))
    {
        depth.setSize(320, 240);
        depth.setFps(30);
        depth.start();
    }
    
#ifdef USE_IR
    if (ir.setup(*device)) // only for xtion device (OpenNI2-FreenectDriver issue)
    {
        ir.setSize(320, 240);
        ir.setFps(30);
        ir.start();
    }
#endif
    
#ifdef USE_RGB
    if (color.setup(*device)) // only for kinect
    {
        color.setSize(320, 240);
        color.setFps(30);
        color.start();
    }
#endif
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
#ifdef USE_IR
    ir.draw();
#endif
    
#ifdef USE_RGB
    color.draw(0,240);
#endif
    
    depth.draw(320, 0);
}

void ofApp::exit(){
    device->exit();
    delete device;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
