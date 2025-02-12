#include <FL/Fl.H>
#include "./functionality/draw.h"

int main(int argc, char **argv) 
{	
	// TODO: check if nmcli is installed at all, and display a "you don't have this installed"
	// screen if not
	//draw_main_app(argc,argv);
	
	draw_no_nmcli_screen();
	return Fl::run();
}