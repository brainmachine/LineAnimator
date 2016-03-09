//Line animator
//Originally written in Processing. Ported to oF for speed and modularity.
//Load an image and read through the horizontal lines
//Each line becomes a series of vertical lines drawn in series to create an animation
//Code by Le— Stef‡nsson 2012


#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    
    //Load the paths
    path = "images";
    ofDirectory _dir(path);
    dir = _dir;
    dir.listDir();
    numFiles = dir.numFiles();
    ofLogNotice("numFiles: " + ofToString(numFiles));
    
    //reserve memory for images
    everyFrame = new ofImage[numFiles];
    
    for (int i = 0; i < numFiles; i++)
    {
        //Get unique file path
        string _path = ofToString(dir.getPath(i));
        
        //Load an image
        otherFrame.loadImage(_path); //read to buffer
        everyFrame[i] = otherFrame;	//assign to unique place in memory
        ofLogNotice("Successfully loaded '" + _path + "'");
        
    }
    ofSetFrameRate(30);
    
}


//--------------------------------------------------------------
void ofApp::update()
{
    
    lineCounter += otherFrame.getWidth()*3;
    //Check if LineCounter is out of bounds and reset and point to next file.
    if (lineCounter >= otherFrame.getWidth()*otherFrame.getHeight()*3)
    {
        lineCounter = 0;
        currentImage++;
        if (currentImage >= numFiles)
        {
            currentImage = 0;
        }
    }
    //Set pixels to point to the current image
    pixels = everyFrame[currentImage].getPixels();
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    
    for (int i = 0; i < otherFrame.getWidth(); i++)
    {
        int r = pixels[lineCounter+i*3];
        int g = pixels[lineCounter+i*3+1];
        int b = pixels[lineCounter+i*3+2];
        
        ofSetColor(r,g,b);//set the color values (r, g, b)
        ofLine(i, 0, i, 1080);
    }
}

