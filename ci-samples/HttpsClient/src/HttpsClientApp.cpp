#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "SimpleHttpsClient.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HttpsClientApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void HttpsClientApp::setup()
{
    
    try
    {

        asio::ssl::context ctx(asio::ssl::context::sslv23);
        ctx.set_default_verify_paths();
        
        string server = "pwc.downstreamlabs.com";
        string path = "/api/checkin";
        client c(App::io_service(), ctx, server, path);
        
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }
    
    
}

void HttpsClientApp::mouseDown( MouseEvent event )
{
}

void HttpsClientApp::update()
{
}

void HttpsClientApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( HttpsClientApp, RendererGl )
