#include "ofApp.h"

//#define USE_RAW_ONI
//#define USE_RGB
//#define USE_IR

#ifdef USE_RAW_ONI

#include <OpenNI.h>
openni::Device device;
openni::VideoStream depth;
#else
#include "ofxNI2.h"

ofxNI2::Device *device;
ofxNI2::DepthStream depth;
#endif

#ifdef USE_IR
ofxNI2::IrStream ir;
#endif

#ifdef USE_RGB
ofxNI2::ColorStream color;
#endif


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);

#ifdef USE_RAW_ONI
    rawOni();
    /*openni::Status rc = openni::STATUS_OK;
    const char * deviceURI = openni::ANY_DEVICE;
    rc = openni::OpenNI::initialize();
    if(rc==openni::STATUS_OK){
        cout<<"Initialization: all good"<<endl;
    }else{
        printf("ERROR After initialization:\n%s\n", openni::OpenNI::getExtendedError());
    }
    
    rc = device.open(deviceURI);
    if(rc!=openni::STATUS_OK){
        printf("ERROR Device open failed:\n%s\n", openni::OpenNI::getExtendedError());
        openni::OpenNI::shutdown();
    }else{
        cout<<"Device: opened"<<endl;
    }
    
    rc = depth.create(device, openni::SENSOR_DEPTH);
    if(rc==openni::STATUS_OK){
        cout<<"Depth: created"<<endl;
        rc = depth.start();
        if(rc!=openni::STATUS_OK){
            printf("ERROR Couldn't start depth stream:\n%s\n", openni::OpenNI::getExtendedError());
            depth.destroy();
        }else{
            cout<<"Depth Started"<<endl;
        }
    }else{
        printf("ERROR Couldn't find depth stream:\n%s\n", openni::OpenNI::getExtendedError());
    }*/
    
#else
    device = new ofxNI2::Device;
    if(device->listDevices()>0){
        device->setup();
    }else{
        cout<<"No devices found: closing"<<endl;
        ofExit();
        return;
    }
    
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
    
#endif
}

void ofApp::rawOni(){
    const char * uri = NULL;
    openni::Status rc = openni::STATUS_OK;
    openni::Device g_device;
    openni::PlaybackControl * g_PlaybackControl = NULL;
    const openni::SensorInfo * sInfo;
    openni::VideoStream stream;
    
    rc = openni::OpenNI::initialize();
    if(rc==openni::STATUS_OK){
        cout<<"Initialization: all good"<<endl;
    }else{
        printf("ERROR After initialization:\n%s\n", openni::OpenNI::getExtendedError());
    }
    
    rc = g_device.open(openni::ANY_DEVICE);
    if(rc!=openni::STATUS_OK){
        cout<<"ERROR Device::open "<<openni::OpenNI::getExtendedError()<<endl;
    }else{
        cout<<"Device::open: all good!"<<endl;
    }
    
    g_PlaybackControl = g_device.getPlaybackControl();
    if(g_PlaybackControl==NULL){
        cout<<"ERROR Device::getPlaybackControl failed"<<endl;
    }else{
        cout<<"ERROR Device::getPlaybackControl: all good!"<<endl;
    }
    
    sInfo = g_device.getSensorInfo(openni::SENSOR_DEPTH);
    if(sInfo==NULL){
        cout<<"ERROR Device::getSensorInfo: no DEPTH found"<<endl;
    }else{
        cout<<"Device::getSensorInfo: DEPTH found!"<<endl;
    }
    
    rc = stream.create(g_device, openni::SENSOR_DEPTH);
    if(rc!=openni::STATUS_OK){
        cout<<"ERROR VideoStream::create "<<openni::OpenNI::getExtendedError()<<endl;
    }else{
        cout<<"VideoStream::create: all good!"<<endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
#ifdef USE_RAW_ONI
    
#else
    
#ifdef USE_IR
    ir.draw();
#endif
    
#ifdef USE_RGB
    color.draw(0,240);
#endif
    
    depth.draw(320, 0);
#endif
}

void ofApp::exit(){
#ifdef USE_RAW_ONI

#else
    device->exit();
    delete device;
#endif
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
