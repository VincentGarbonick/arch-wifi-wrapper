#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

int main(int argc, char **argv) {
    Fl_Window *window = new Fl_Window(300, 200, "Hello, FLTK!");
    Fl_Button *button = new Fl_Button(100, 100, 100, 30, "Click me");
    window->end();
    window->show(argc, argv);
    return Fl::run();
}
