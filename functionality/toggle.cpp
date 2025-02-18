#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <string>
#include <sstream>
#include <algorithm>
#include "run.h"
#include "toggle.h"
#include "scan.h"
#include "label.h"
#include "../constants/main_constants.h"
#include "../constants/callback_data.h"

// TODO: update wifi status bar when you toggle shit, by using the print_wifi_status funciton 
void toggle_wifi(Fl_Widget* wifi_button, void* t)
{
	callback_data::toggle_args* toggle_args = (callback_data::toggle_args*)t;
	std::string command_result = get_wifi_status();
	// TODO: error handling?
	if(command_result == NMCLI_WIFI_ENABLED) 
	{
		command_result = run_command(CMD_WIFI_OFF, toggle_args->output);
		safe_toggle_button_text(NMCLI_WIFI_DISABLED,
								wifi_button,
								toggle_args,
								DISABLED_WIFI,
								DISABLED_SUCCESSFUL_MESSAGE);
	}
	else
	{
		command_result = run_command(CMD_WIFI_ON, toggle_args->output);
		safe_toggle_button_text(NMCLI_WIFI_ENABLED,
								wifi_button,
								toggle_args,
								ENABLED_WIFI,
								ENABLED_SUCCESSFUL_MESSAGE);
	}
	return;
}

// ensure we only toggle label if the result is what we want
void safe_toggle_button_text(std::string desired_output,
							 Fl_Widget * button,
							 callback_data::toggle_args * toggle_args,
							 const char * toggle_to,
							 const char * output_successful_message)
{
	std::string current_wifi_status = get_wifi_status();
	if(current_wifi_status == desired_output)
	{
		button->label(toggle_to);
		button->redraw();
		toggle_args->output->value(output_successful_message);
		toggle_args->output->redraw();
		toggle_args->wifi_status->value(label::get_wifi_connection_ssid_label_toggle().c_str());
		toggle_args->wifi_status->redraw();
	}
	else
	{
		std::cout << "There was some kind of error when toggling" << std::endl;
		toggle_args->output->value(TOGGLE_ERROR);
		toggle_args->output->redraw();
		toggle_args->wifi_status->value(TOGGLE_ERROR);		
		toggle_args->wifi_status->redraw();
	}
}

std::string get_wifi_status()
{
	std::string current_wifi_status = run_command(CMD_WIFI_CHECK);
	// result has a newline, so we must trim it
	current_wifi_status.erase(std::remove(current_wifi_status.begin(), 
						  				  current_wifi_status.end(), '\n'), 
						  				  current_wifi_status.end());
	return current_wifi_status;
}
