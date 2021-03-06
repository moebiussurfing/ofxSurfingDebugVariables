#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	//--

	// add variabes

	title = "APP INFO\n";
	ofxSurfingDebugVariables::setTitle(title);

	// name not showed in text type
	ofxSurfingDebugVariables::addText("HELP :");
	ofxSurfingDebugVariables::addText("KEY [?] : HIDE/SHOW");
	ofxSurfingDebugVariables::addText("these are hardcoded text lines");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("DEBUG:");
	ofxSurfingDebugVariables::addString("myString2", &str2);
	ofxSurfingDebugVariables::addFloat("myFloat1", &f1);
	ofxSurfingDebugVariables::addFloat("myFloat2", &f2);
	ofxSurfingDebugVariables::addFloat("myFloat3", &f3);
	ofxSurfingDebugVariables::addString("myString1", &str1);
	ofxSurfingDebugVariables::addText("these are referenced variables");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("COUNTERS:");
	ofxSurfingDebugVariables::addInt("myInt1 (frameNum)", &i1);
	ofxSurfingDebugVariables::addInt("myInt2 (seconds)", &i2);
	ofxSurfingDebugVariables::addFloat("myFloat4 ", &f4);
	ofxSurfingDebugVariables::addNewLine();

	//ofParameters
	ofxSurfingDebugVariables::addText("PARAMETERS:");
	ofxSurfingDebugVariables::addParamFloat(myParamFloat);
	ofxSurfingDebugVariables::addParamInt(myParamInt);
	ofxSurfingDebugVariables::addText("these are ofParameters");
	ofxSurfingDebugVariables::addNewLine();

	ofxSurfingDebugVariables::addText("SWITCHES:");
	ofxSurfingDebugVariables::addBool("myBool1", &b1);
	ofxSurfingDebugVariables::addBool("myBool2", &b2);

	//----

	// cutomization

	// show box. hidden by default
	ofxSurfingDebugVariables::setShowing(true);

	// customize font
	// draws with ofTrueTypeFont if loaded
	fontSize = 9;
	string path = "assets/fonts/";
	path += "overpass-mono-bold.otf";
	//path += "mono.ttf";
	ofxSurfingDebugVariables::loadFont(path, fontSize);
}

//--------------------------------------------------------------
void ofApp::update() {
	// nothing more to do

	// simulate artificial variations on our variables
	// make random changes to our variables to demo

	auto time = ofGetFrameNum();

	// string
	float myRandom = ofNoise(time / 60.f, 2);
	switch ((int) (5 * myRandom)) {
	case 0:
		str1 = "|----";
		break;
	case 1:
		str1 = "-|---";
		break;
	case 2:
		str1 = "--|--";
		break;
	case 3:
		str1 = "---|-";
		break;
	case 4:
		str1 = "----|";
		break;
	default:
		break;
	}

	// string
	str2 = ofToString(time);

	// floats
	f1 = ofRandom(0, 1);
	f2 = ofRandom(0, 1);
	f3 = ofRandom(0, 1);
	f4 = ofRandom(0, 1);

	// ints
	i1 = time;
	i2 = ofGetFrameNum() % 60;

	if (ofGetFrameNum() % 60 == 0)
	{
		// bool
		b1 = !b1;

		// param float
		myParamFloat = ofRandom(myParamFloat.getMin(), myParamFloat.getMax());
	}

	// param int
	myParamInt = ofMap(myRandom * myParamInt.getMax(), 0, 1, myParamInt.getMin(), myParamInt.getMax());

	// bool
	if (myRandom == 4) b2 = !b2;
}

//--------------------------------------------------------------
void ofApp::draw() {
	// nothing more
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofxSurfingDebugVariables::exit();//required to auto save/handle box position
}