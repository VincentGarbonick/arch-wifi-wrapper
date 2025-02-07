#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Select_Browser.H>

void test(Fl_Widget* w, void* p)
{
	((Fl_Select_Browser*)p)->add("skibidi");
	return;
}
