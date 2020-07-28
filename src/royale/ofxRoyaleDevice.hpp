//
//  ofxRoyaleDevice.hpp
//
//  Created by enrico<naus3a>viola on 7/28/20.
//

#pragma once
#include "ofxNI2.h"
#include <royale.hpp>
#include "RoyaleOpenNI2Device.hpp"

namespace ofxRoyale {
    class ofxRoyaleDevice{
    public:
        ofxRoyaleDevice();
        void setFromDepthStream();
        bool isReady(){return bReady;}
    private:
        void reset();
        
        royale::openni2::RoyaleOpenNI2Device * rNi2Dev;
        bool bReady;
    };
}
