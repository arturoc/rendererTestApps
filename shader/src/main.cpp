#include "ofMain.h"
#include "ofGLProgrammableRenderer.h"

class ofApp : public ofBaseApp{
public:
    ofImage testImage;
    ofShader shader;
    void setup()
	{
        ofSetLogLevel(OF_LOG_VERBOSE);
        testImage.loadImage("of.png");
		shader.load("shader");
    }
	
	
	
    void update()
	{
		
    }

    void draw()
	{
		shader.begin();
			shader.setUniformTexture("myTexture", testImage.getTextureReference(), testImage.getTextureReference().texData.textureID);
			testImage.draw(0, 0);
		shader.end();
		
		stringstream info;
		info << "This text should be yellow" << "\n";
		//ofPushStyle();
			ofDrawBitmapStringHighlight(info.str(), testImage.getWidth(), 100, ofColor::black, ofColor::yellow);
		//ofPopStyle();
		ofSetColor(ofColor::yellow);

		ofCircle(100, 400, 100);
		
    }
};

//========================================================================
int main( ){

    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE); 
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp( new ofApp());

}