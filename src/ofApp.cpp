#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  shader.load("shader");
  videoGrabber.setup(ofGetWidth(), ofGetHeight());
  videoGrabber.setDeviceID(devID);
  fbo.allocate(640, 480);
}

//--------------------------------------------------------------
void ofApp::update()
{
  ofDisableArbTex(); // normalise the coords
  videoGrabber.update();
  if (devID != prevDevID)
  {
    videoGrabber.close();
    videoGrabber.setDeviceID(devID);
    videoGrabber.setup(ofGetWidth(), ofGetHeight());
    prevDevID = devID;
  }
  if (videoGrabber.isFrameNew())
  {
    fbo.begin();
    ofClear(0, 0, 0, 0);
    shader.begin();
    shader.setUniform1f("u_zoom", zoom);
    shader.setUniform2f("u_offset", offsetX, offsetY);
    shader.setUniformTexture("u_texture", videoGrabber.getTexture(), 0);
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();
    fbo.end();
  }
}

//--------------------------------------------------------------
void ofApp::draw()
{
  fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
  videoGrabber.draw(ofGetWidth() - ((ofGetWidth() / 4) + 10), 10, ofGetWidth() / 4, ofGetHeight() / 4);
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  if (key == ' ' || key == '0')
  {
    vector<ofVideoDevice> devices = videoGrabber.listDevices();
    if (devID < devices.size())
    {
      devID++;
    }
    else
    {
      devID = 0;
    }
  }
  if (key == '1')
  {
    zoom += 0.1f;
  }
  if (key == '2')
  {
    zoom -= 0.1f;
  }
  if (key == '3')
  {
    offsetX += 0.1f;
  }
  if (key == '4')
  {
    offsetX -= 0.1f;
  }
  if (key == '5')
  {
    offsetY += 0.1f;
  }
  if (key == '6')
  {
    offsetY -= 0.1f;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
