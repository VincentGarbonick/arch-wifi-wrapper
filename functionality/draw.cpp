#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include "scan.h"
#include "run.h"
#include "exit.h"
#include "toggle.h"
#include "label.h"
#include "../constants/main_constants.h"
#include "../constants/no_nmcli_constants.h"
#include "../constants/callback_data.h"
#include <iostream>
// TODO: does putting our window/app definitions in a function make this cause memory leaks?
// or is it safe to do so?
void draw_main_app(int argc, char **argv)
{
	Fl_Window *window = new Fl_Window(PARENT_WIDTH, PARENT_HEIGHT, APPNAME);
 	Fl_Select_Browser *browser = new Fl_Select_Browser(
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
					label::get_wifi_button_label()
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
	status_bar->value(WELCOME_MESSAGE);
	status_bar->redraw();
	current_bar->value(label::get_initial_current_conn_label().c_str());
	current_bar->redraw();

	static scan_args s_args{browser, status_bar};
	scan_button->callback(scan, &s_args);

	enable_button->callback(toggle_wifi, status_bar);
	exit_button->callback(close_app);
	window->end();
	window->show(argc, argv);
}

void draw_no_nmcli_screen()
{
	fl_message_title(no_nmcli_constants::TITLE);
	fl_message(no_nmcli_constants::MESSAGE);
}

bool host_has_nmcli()
{
	int exit_status = run_command_get_exit_status(CMD_WIFI_CHECK);

	if(exit_status == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}