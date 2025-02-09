#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

void close_app(Fl_Widget* w, void* data) {
    // Flush any pending events/graphics
    Fl::flush();
    // Hide all windows. Iterates through FLTK's window list
    Fl_Window* window;
    while ((window = Fl::first_window())) {
        window->hide();
    }
    // Remove any pending timeouts
    Fl::remove_timeout((void (*)(void*))exit, 0);
    exit(0);
}