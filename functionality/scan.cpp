#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>

void scan(Fl_Widget* w, void* p)
{
	Fl_Select_Browser* browser = ((Fl_Select_Browser*)p);
	browser->add("hi");
	return;
}
