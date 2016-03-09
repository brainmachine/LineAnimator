#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    
    ofDirectory dir;
    string path; //we needpaths for our images
    string * currentPath;
    ofImage otherFrame; //this is used to load a single image (kind of like a buffer)
    ofImage * everyFrame;
    unsigned char * pixels;	//this points to raw pixel {r, g, b, ...} at the ofImage 'everyFrame[i]' in memory.
    
    int numFiles; //number of frames loaded
    int currentImage; //set the image to read from
    int lineCounter; //set the position to read from everyFrame
    
    
    
};
