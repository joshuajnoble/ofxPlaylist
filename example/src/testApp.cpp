#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);
	
	
	ofxKeyframeAnimRegisterEvents(this);
	
for (int i=0; i<20; i++) {
	animatedRectangles.push_back(new AnimatedRectangle());
	// animatedRectangles[i]->playlist.attach();	
	ofxKeyframeAnimRegisterEvents(animatedRectangles[i]);

}	
	
	// masterPlaylist.attach();
	
}

//--------------------------------------------------------------
void testApp::update(){
	vector<AnimatedRectangle *>::iterator it = animatedRectangles.begin();
	
	for (int i=0; i<20; i++) {
		animatedRectangles[i]->playlist.update();	
	}	

}

void testApp::onKeyframe(ofxPlaylistEventArgs& args){

	// this check is only necessary if you want to be absolutely sure that 
	// the onKeyFrame Event was sent by the same object as the receiver.
	if (args.pSender != static_cast<void*>(this)) return;
	
	ofLog(OF_LOG_VERBOSE) << "Keyframe Event received for (" << args.pSender << "): " << args.message << ": " << ofGetFrameNum();

}

//--------------------------------------------------------------
void testApp::draw(){
	vector<AnimatedRectangle *>::iterator it = animatedRectangles.begin();
	
	while (it != animatedRectangles.end()) {
		// draw that Rectangle.
		(*it)->draw();
		it++;
	}
	
	ofDrawBitmapString(ofToString(ofGetFrameNum()) + ":" + ofToString(ofGetFrameRate()),ofPoint(ofGetWidth()/2.,ofGetHeight()/2.));
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	using namespace Playlist;
	int index = int(ofRandom(animatedRectangles.size()));
	
	// first an elegant combined movement,


	AnimatedRectangle * pRect = animatedRectangles[index];
	
	pRect->playlist.addKeyFrame(Action::event(pRect,"START1"));
	pRect->playlist.addKeyFrame(Action::tween(100, &pRect->pos.y, ofRandomuf()*ofGetHeight(), TWEEN_QUAD, TWEEN_EASE_OUT));
	pRect->playlist.addKeyFrame(Action::event(this,"START2"));
	pRect->playlist.addKeyFrame(Action::event(this,"START3"));
	pRect->playlist.addKeyFrame(Action::pause(100));
	pRect->playlist.addKeyFrame(Action::tween(100, &pRect->pos.x, ofRandomuf()*ofGetWidth(), TWEEN_QUAD, TWEEN_EASE_OUT));
	pRect->playlist.addKeyFrame(Action::event(this,"START5"));
	pRect->playlist.addToKeyFrame(Action::tween(100, &pRect->angle,  ofRandomuf()*360, TWEEN_SIN, TWEEN_EASE_IN_OUT));
	pRect->playlist.addKeyFrame(Action::event(this,"END"));

//	// then a delicate change colour change.

	//	animatedRectangles[index]->addNewKeyFrame(new Tweener(&quadE, &animatedRectangles[index]->color.r, TWEEN_EASE_IN_OUT, &animatedRectangles[index]->color.r, ofRandomuf()*255.f, 20));
	//	animatedRectangles[index]->addToKeyFrame(new Tweener(&sinE, &animatedRectangles[index]->color.g, TWEEN_EASE_IN_OUT, &animatedRectangles[index]->color.g, ofRandomuf()*255.f, 20));
	//	animatedRectangles[index]->addToKeyFrame(new Tweener(&sinE, &animatedRectangles[index]->color.b, TWEEN_EASE_OUT, &animatedRectangles[index]->color.b, ofRandomuf()*255.f, 20));
	//	animatedRectangles[index]->addNewKeyFrame(new EventKeyframe(this,"LAST"));

	ofLog(OF_LOG_VERBOSE) << "Duration: " << animatedRectangles[index]->playlist.duration;
	

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}