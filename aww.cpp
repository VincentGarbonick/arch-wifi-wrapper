#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <string>
#include <iostream>
#include <cmath>

int PARENT_WIDTH = 500;
int PARENT_HEIGHT = 500;
int WIFI_BROWSER_WIDTH = PARENT_WIDTH - 20;
int WIFI_BROWSER_HEIGHT = ceil(PARENT_HEIGHT / 2); // ensure we are using a whole number
int WIFI_BROWSER_OFFSET_X = 10;
int WIFI_BROWSER_OFFSET_Y = 10;
const char * APPNAME = "Arch Wifi Wrapper";
const char * WIFI_LIST = "Wifi List";

int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(PARENT_WIDTH, PARENT_HEIGHT, APPNAME);
 	Fl_Select_Browser browser(WIFI_BROWSER_OFFSET_X, 
				  WIFI_BROWSER_OFFSET_Y,
				  WIFI_BROWSER_WIDTH,
				  WIFI_BROWSER_HEIGHT, 
				  WIFI_LIST);
	browser.add("fartmannnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn");
	for(int i = 0; i < 30; i++)
	{
		browser.add("chungus");
	}
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
