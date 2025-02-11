#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Output.H>
#include "functionality/scan.h"
#include "functionality/run.h"
#include "functionality/exit.h"
#include "functionality/toggle.h"
#include "constants/constants.h"
#include "constants/callback-data.h"

int main(int argc, char **argv) 
{
	Fl_Window *window = new Fl_Window(PARENT_WIDTH, PARENT_HEIGHT, APPNAME);

 	Fl_Select_Browser browser(
					WIFI_BROWSER_OFFSET_X, 
				  	WIFI_BROWSER_OFFSET_Y,
				  	WIFI_BROWSER_WIDTH,
				  	WIFI_BROWSER_HEIGHT
				);
	
	Fl_Output *current_bar = new Fl_Output(
					CURRENT_BAR_OFFSET_X,
					CURRENT_BAR_OFFSET_Y,
					CURRENT_BAR_WIDTH,
					CURRENT_BAR_HEIGHT
				);

	Fl_Output *status_bar = new Fl_Output(
					STATUS_BAR_OFFSET_X,
					STATUS_BAR_OFFSET_Y,
					STATUS_BAR_WIDTH,
					STATUS_BAR_HEIGHT
				);

	Fl_Button *scan_button = new Fl_Button(
					WIFI_SCAN_BUTTON_OFFSET_X,
					WIFI_SCAN_BUTTON_OFFSET_Y,
					WIFI_SCAN_BUTTON_WIDTH,
					WIFI_SCAN_BUTTON_HEIGHT,
					WIFI_SCAN
				);
	
	Fl_Button *connect_button = new Fl_Button(
					CONNECT_BUTTON_OFFSET_X,
					CONNECT_BUTTON_OFFSET_Y,
					CONNECT_BUTTON_WIDTH,
					CONNECT_BUTTON_HEIGHT,
					CONNECT
				);

	Fl_Button *forget_button = new Fl_Button(
					FORGET_BUTTON_OFFSET_X,
					FORGET_BUTTON_OFFSET_Y,
					FORGET_BUTTON_WIDTH,
					FORGET_BUTTON_HEIGHT,
					FORGET
				);

	Fl_Button *enable_button = new Fl_Button(
					ENABLE_BUTTON_OFFSET_X,
					ENABLE_BUTTON_OFFSET_Y,
					ENABLE_BUTTON_WIDTH,
					ENABLE_BUTTON_HEIGHT,
					ENABLED_WIFI
				);

	Fl_Button *help_button = new Fl_Button(
					HELP_BUTTON_OFFSET_X,
					HELP_BUTTON_OFFSET_Y,
					HELP_BUTTON_WIDTH,
					HELP_BUTTON_HEIGHT,
					HELP
				);

	Fl_Button *exit_button = new Fl_Button(
					EXIT_BUTTON_OFFSET_X,
					EXIT_BUTTON_OFFSET_Y,
					EXIT_BUTTON_WIDTH,
					EXIT_BUTTON_HEIGHT,
					EXIT
	);

	static scan_args s_args{&browser, status_bar};
	scan_button->callback(scan, &s_args);
	enable_button->callback(toggle_wifi, status_bar);
	exit_button->callback(close_app);
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
