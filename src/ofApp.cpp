#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //  window
    ofSetWindowShape(1280, 960);
    //  camera
    camera.initGrabber(640, 480);
    //  allocate images
    grayImage.allocate(640, 480);
    edgeImage.allocate(640, 480);
    blackImage.allocate(640, 480);
    whiteImage.allocate(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    //  camera
    camera.update();
    colorImage.setFromPixels(camera.getPixels());
    grayImage = colorImage;
    blackImage = colorImage;
    whiteImage=colorImage;
    grayImage.blur(3);
    blackImage.blur(3);
    //  canny filter
    int minVal = 60;
    int maxVal = 150;
    cvCanny(grayImage.getCvImage(), edgeImage.getCvImage(), minVal,  maxVal, 3);
    cvCanny(blackImage.getCvImage(), edgeImage.getCvImage(), 50,  100, 3);
//    cvCanny(grayImage.getCvImage(), edgeImage.getCvImage(), 20, 100);
    edgeImage.flagImageChanged();
    edgeImage.dilate();
    blackImage.flagImageChanged();
    blackImage.dilate();
    //  posterization
    unsigned char *grayData = grayImage.getPixels();
    unsigned char *edgeData = edgeImage.getPixels();
    unsigned char *blackData = blackImage.getPixels();
    unsigned char *whiteData = whiteImage.getPixels();
    
    for (int i = 0; i < 640*480; i++) {
       
            grayData[i] = (grayData[i] / 64) * 64 + 80;
        }
    grayImage.flagImageChanged();

    for (int i = 0; i < 640*480; i++) {
        if (edgeData[i] == 0){
            blackData[i] = 255;
           
        }else{
            blackData[i] = 0;
        }}

    blackImage.flagImageChanged();
    
    for (int i = 0; i < 640*480; i++) {
        if (edgeData[i] == 0){
            whiteData[i] = 0;
            
        }else{
            whiteData[i] = 255;
        }}
    
    whiteImage.flagImageChanged();
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.draw(0, 0, 640, 480);
    grayImage.draw(640, 0, 640, 480);
    blackImage.draw(0, 480, 640, 480);
    whiteImage.draw(640,480,640,480);
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
