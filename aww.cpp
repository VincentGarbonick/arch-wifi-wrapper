#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Select_Browser.H>

int main(int argc, char **argv) {
	Fl_Window *window = new Fl_Window(500, 500, "Hello, FLTK!");
	//Fl_Button *button = new Fl_Button(100, 100, 100, 30, "Click me");
 	Fl_Select_Browser browser(10,10,300,300,"Test");
	browser.add("fartman");
	for(int i = 0; i < 30; i++)
	{
		browser.add("chungus");
	}
	window->end();
	window->show(argc, argv);
	return Fl::run();
}
