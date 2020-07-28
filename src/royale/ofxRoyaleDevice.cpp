//
//  ofxRoyaleDevice.cpp
//
//  Created by enrico<naus3a>viola on 7/28/20.
//


#include "ofxRoyaleDevice.hpp"

using namespace ofxRoyale;

ofxRoyaleDevice::ofxRoyaleDevice(){
    reset();
}

void ofxRoyaleDevice::reset(){
    rNi2Dev = NULL;
    bReady = false;
}

