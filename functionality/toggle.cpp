#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <string>
#include <sstream>
#include <algorithm>
#include "run.h"
#include "toggle.h"
#include "../constants/constants.h"

void toggle_wifi(Fl_Widget* wifi_button, void* p_status_bar)
{
	Fl_Output* status_bar = ((Fl_Output*)p_status_bar);
	std::string command_result = get_wifi_status();
	// TODO: error handling?
	if(command_result == NMCLI_WIFI_ENABLED) 
	{
		command_result = run_command(CMD_WIFI_OFF, status_bar);
		safe_toggle_button_text(NMCLI_WIFI_DISABLED,
								wifi_button,
								status_bar,
								DISABLED_WIFI,
								DISABLED_SUCCESSFUL_MESSAGE);
	}
	else
	{
		command_result = run_command(CMD_WIFI_ON, status_bar);
		safe_toggle_button_text(NMCLI_WIFI_ENABLED,
								wifi_button,
								status_bar,
								ENABLED_WIFI,
								ENABLED_SUCCESSFUL_MESSAGE);
	}

	return;
}

// ensure we only toggle label if the result is what we want
void safe_toggle_button_text(std::string desired_output,
							 Fl_Widget * button,
							 Fl_Output * status_bar,
							 const char * toggle_to,
							 const char * output_successful_message)
{
	std::string current_wifi_status = get_wifi_status();
	if(current_wifi_status == desired_output)
	{
		button->label(toggle_to);
		button->redraw();
		status_bar->label(output_successful_message);
		status_bar->redraw();
	}
	else
	{
		std::cout << "There was some kind of error when toggling" << std::endl;
		status_bar->label(TOGGLE_ERROR);
		status_bar->redraw();
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
