#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

  private:
	float red;
	float green;
	float blue;
};

void CatPictureApp::setup()
{
	red = 0.0f;
	green = 0.0f;
	blue = 0.0f;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	red = red + 0.005f;
	if(red > 1.0f)
	{
		red = red - 0.005f;
		green = green + 0.005f;
		if (green > 1.0f)
		{
			green = green - 0.005f;
			blue = blue + 0.005f;
			if (blue > 1.0f)
			{
				red = 0.0f;
				green = 0.0f;
				blue = 0.0f;
			}
		}
	}
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( red, green, blue ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
