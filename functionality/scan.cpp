#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>
#include <string>
#include "run.h"
#include "../constants/constants.h"

void scan(Fl_Widget* w, void* p)
{
	Fl_Select_Browser* browser = ((Fl_Select_Browser*)p);

	std::string scan_output = run_command(CMD_SCAN_WIFI);
	std::cout << scan_output << std::endl;
	//browser->add("hi");
	//parse_wifi_list("fart");
	return;
}
