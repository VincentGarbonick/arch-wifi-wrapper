#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>
#include <string>
#include <sstream>
#include "run.h"
#include "parse.h"
#include "../constants/constants.h"
#include "../constants/callback-data.h"

void scan(Fl_Widget* w, void* p)
{
	scan_args* s_args = ((scan_args*)p);
	s_args->browser->clear();
	std::string scan_output = run_command(CMD_SCAN_WIFI, s_args->output);
	// TOOD: make our scan command return some kind of false value/undefined to see if this works
	// we had some kind of failure
	if(scan_output == "") // check for null/undefined too
	{
		// we're already sending error message when it doesn't work in run
		return;
	}
	s_args->output->value(SCAN_SUCCESSFUL);
	s_args->output->redraw();
	std::istringstream stream(scan_output); 
    std::string line;
	parsed_ncmli_list_output parsed_ncmli_element_output;
	std::string formatted_line;
    
	// TODO: color output
    while(std::getline(stream, line)) 
	{
		parsed_ncmli_element_output = parse_nmcli_list_output(line, false);
		std::ostringstream format_stream;
    	format_stream 
				<< parsed_ncmli_element_output.full_mac 
				<< "\t" 
				<< parsed_ncmli_element_output.network_name;
    	std::string formatted_line = format_stream.str();
		s_args->browser->add(formatted_line.c_str());
    }
	return;
}
