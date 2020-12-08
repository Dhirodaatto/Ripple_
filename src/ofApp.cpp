#include "ofApp.h"

//--------------------------------------------------------------
double phase = 0;
double damp_offset;
int X = 20, Y = 20;


void ofApp::setup()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			displacements[i][j] = 0;
		}

	}
	
	
	ofBackground(ofColor().black);
	ofNoFill();
	
	ofSetColor(ofColor().blue);

	mesh.setMode(OF_PRIMITIVE_LINE_STRIP);


}

//--------------------------------------------------------------
void ofApp::update()
{
	phase -= 0.2;


	for (int y = 0; y < nr; y++) {

		for (int x = 0; x < nc; x++) {

			float r = sqrt((X - x)*(X - x) + (Y - y)*(Y - y));
			
			damp_offset = exp(-0.08*r);
			

			displacements[y][x] = 10 * damp_offset * sin(r + phase);

		}

	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofTranslate(ofPoint(ofGetWidth()/4, ofGetHeight()/3, 0));
	ofRotateXDeg(60);
	for (int i = 0; i < 1000; i += 20)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (int j = 0; j <= 1000; j += 20)
		{
			glVertex3f(i, j, displacements[i / 20][j / 20]);
			glVertex3f(i + 20, j, displacements[(i + 20) / 20][j / 20]);
		}
		glEnd();
	}

	//ofRotateXDeg(-60);
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
