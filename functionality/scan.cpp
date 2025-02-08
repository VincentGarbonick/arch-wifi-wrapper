#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>
#include <string>
#include <sstream>
#include "run.h"
#include "../constants/constants.h"

void scan(Fl_Widget* w, void* p)
{
	Fl_Select_Browser* browser = ((Fl_Select_Browser*)p);
	browser->clear();
	std::string scan_output = run_command(CMD_SCAN_WIFI);
	std::istringstream stream(scan_output); 
    std::string line;
    
    while(std::getline(stream, line)) {
		browser->add(line.c_str());
    }
	return;
}
