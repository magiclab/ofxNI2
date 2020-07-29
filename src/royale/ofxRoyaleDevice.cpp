//
//  ofxRoyaleDevice.cpp
//
//  Created by enrico<naus3a>viola on 7/28/20.
//


#include "ofxRoyaleDevice.hpp"

using namespace ofxRoyale;

royale::String ofxRoyaleDevice::getCurrentUseCase(ofxNI2::Device * dev){
    int dSz = sizeof(royale::String);
    royale::String ucStr;
    dev->get().getProperty(royale::openni2::RoyaleOpenNI2Device::ONI_DEVICE_PROPERTY_ROAYLE_USECASE, &ucStr, &dSz);
    return ucStr;
}

bool ofxRoyaleDevice::setUseCase(ofxNI2::Device * dev, royale::openni2::RoyaleOpenNI2Device::RoyaleUseCase uc){
    int dSz = sizeof(royale::String);
    royale::String ucStr = royale::openni2::RoyaleOpenNI2Device::getUseCaseString(uc);
    openni::Status rc =  dev->get().setProperty(royale::openni2::RoyaleOpenNI2Device::ONI_DEVICE_PROPERTY_ROAYLE_USECASE, &ucStr, dSz);
    return (rc==openni::STATUS_OK);
}

