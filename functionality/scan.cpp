#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>
#include <string>
#include "scan.h"

void scan(Fl_Widget* w, void* p)
{
	Fl_Select_Browser* browser = ((Fl_Select_Browser*)p);
	browser->add("hi");
	parse_wifi_list("fart");
	return;
}

void parse_wifi_list(std::string wifi_list)
{
	std::cout << "hello" << std::endl;
	return;
}
