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
	Fl_Select_Browser* browser = ((Fl_Select_Browser*)p);
	browser->clear();
	std::string scan_output = run_command(CMD_SCAN_WIFI);
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
		browser->add(formatted_line.c_str());
    }
	return;
}
