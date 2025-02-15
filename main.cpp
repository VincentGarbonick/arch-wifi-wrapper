#include <FL/Fl.H>
#include "./functionality/draw.h"
#include <stdlib.h>
#include <iostream>
#include "./constants/main_constants.h"
#include "./functionality/run.h"

int main(int argc, char **argv) 
{	
	// TODO: check if nmcli is installed at all, and display a "you don't have this installed"
	// screen if not
	//draw_main_app(argc,argv);
	
	// draw_no_nmcli_screen();
	// return Fl::run();

	std::cout << run_command_get_exit_status(CMD_WIFI_CHECK) << std::endl;

	return 0;
}