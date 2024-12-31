#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	ofGLESWindowSettings settings;
	settings.setGLESVersion(2);
	settings.setSize(640, 480);

	settings.windowMode = OF_WINDOW; // can also be OF_FULLSCREEN

	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}
