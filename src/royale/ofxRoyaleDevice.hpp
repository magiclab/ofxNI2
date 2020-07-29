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
        static royale::String getCurrentUseCase(ofxNI2::Device * dev);
        static bool setUseCase(ofxNI2::Device * dev, royale::openni2::RoyaleOpenNI2Device::RoyaleUseCase uc);
    };
}
