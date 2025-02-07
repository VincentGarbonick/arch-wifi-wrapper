#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <iostream>
#include "functionality/scan.h"

int PARENT_WIDTH = 500;
int PARENT_HEIGHT = 500;
int PARENT_MARGIN_X = 10;
int PARENT_MARGIN_Y = 10;
int WIFI_BROWSER_WIDTH = PARENT_WIDTH - 20;
int WIFI_BROWSER_HEIGHT = PARENT_HEIGHT / 2;
int WIFI_BROWSER_OFFSET_X = PARENT_MARGIN_X;
int WIFI_BROWSER_OFFSET_Y = PARENT_MARGIN_Y;
int WIFI_SCAN_BUTTON_WIDTH = 150; 
int WIFI_SCAN_BUTTON_HEIGHT = 30;
int WIFI_SCAN_BUTTON_OFFSET_X = PARENT_MARGIN_X;
int WIFI_SCAN_BUTTON_OFFSET_Y = WIFI_BROWSER_HEIGHT + 20;
const char * APPNAME = "Arch Wifi Wrapper";
const char * WIFI_LIST = "Wifi List";
const char * WIFI_SCAN = "Scan for Networks";

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
	
	int myNumber = 4;
	scan_button->callback(test, &browser);

	window->end();
	window->show(argc, argv);
	return Fl::run();
}
