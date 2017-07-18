#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	this->noise_source_r = ofRandom(10);
	this->noise_source_g = ofRandom(10);
	this->noise_source_b = ofRandom(10);

	//ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	cam.begin();

	ofRotateZ(90);

	for (int x = -ofGetWidth() / 2; x < ofGetWidth() / 2 + 25; x += 25)
	{
		for (int y = -ofGetHeight() / 2; y < ofGetHeight() / 2 + 25; y += 25) {

			ofPushMatrix();
			ofTranslate(x, y, 0);

			//ofSetColor(255, 0, 0);
			float noise_r = ofNoise(this->noise_source_r, x * 0.0025, y * 0.0025);
			//ofRect(ofVec3f(x, y, 0), 25 * noise_r, 25 * noise_r);

			//ofSetColor(0, 255, 0);
			float noise_g = ofNoise(this->noise_source_g, x * 0.0025, y * 0.0025);
			//ofRect(ofVec3f(x, y, 0), 25 * noise_g, 25 * noise_g);

			//ofSetColor(0, 0, 255);
			float noise_b = ofNoise(this->noise_source_b, x * 0.0025, y * 0.0025);
			//ofRect(ofVec3f(x, y, 0), 25 * noise_b, 25 * noise_b);

			ofRotateX(noise_r * 360);
			ofRotateY(noise_g * 360);
			ofRotateZ(noise_b * 360);

			ofColor c;
			c.setHsb((noise_r + noise_g + noise_b) / 3.0 * 255, 255, 255);
			ofSetColor(c);
			//ofRect(ofVec3f(x, y, 0), 23, 23);
			//ofBox(20);
			ofSphere(ofVec3f(x, y, 0), 10);

			ofPopMatrix();
		}
	}

	this->noise_source_r += 0.005;
	this->noise_source_g += 0.005;
	this->noise_source_b += 0.005;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}