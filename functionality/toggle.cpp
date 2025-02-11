#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Output.H>
#include <string>
#include <sstream>
#include <algorithm>
#include "run.h"
#include "../constants/constants.h"

void toggle_wifi(Fl_Widget* w, void* p)
{
	Fl_Output* output = ((Fl_Output*)p);
	output->value("farty poopy shitty");
	output->redraw();

	std::string current_wifi_status = run_command(CMD_WIFI_CHECK);
	// result has a newline, so we must trim it
	current_wifi_status.erase(std::remove(current_wifi_status.begin(), 
						  				  current_wifi_status.end(), '\n'), 
						  				  current_wifi_status.end());

	if(current_wifi_status == NMCLI_WIFI_ENABLED) 
	{
		std::cout << "wifi enabled" << std::endl;
	}
	else
	{
		std::cout << "wifi disabled" << std::endl;
	}

    // placeholder for real function 
    
	// std::string scan_output = run_command(CMD_SCAN_WIFI);

    
	// // TODO: color output
    // while(std::getline(stream, line)) 
	// {
	// 	parsed_ncmli_element_output = parse_nmcli_list_output(line, false);
	// 	std::ostringstream format_stream;
    // 	format_stream 
	// 			<< parsed_ncmli_element_output.full_mac 
	// 			<< "\t" 
	// 			<< parsed_ncmli_element_output.network_name;
    // 	std::string formatted_line = format_stream.str();
	// 	browser->add(formatted_line.c_str());
    // }
	return;
}
