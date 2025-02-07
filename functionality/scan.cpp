#include <iostream>
#include <FL/Fl.H>

void test(Fl_Widget* w, void* p)
{
	std::cout << "hello world" << std::endl;
	std::cout << *(static_cast<int*>(p)) << std::endl;
}
