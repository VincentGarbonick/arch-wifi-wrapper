#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <iostream>
#include "functionality/scan.h"
#include "functionality/run.h"
#include "constants/constants.h"

int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(PARENT_WIDTH, PARENT_HEIGHT, APPNAME);
 	Fl_Select_Browser browser(WIFI_BROWSER_OFFSET_X, 
				  WIFI_BROWSER_OFFSET_Y,
				  WIFI_BROWSER_WIDTH,
				  WIFI_BROWSER_HEIGHT);

	Fl_Button *scan_button = new Fl_Button(WIFI_SCAN_BUTTON_OFFSET_X,
					 WIFI_SCAN_BUTTON_OFFSET_Y,
					 WIFI_SCAN_BUTTON_WIDTH,
					 WIFI_SCAN_BUTTON_HEIGHT,
					 WIFI_SCAN);
	
	scan_button->callback(scan, &browser);
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
