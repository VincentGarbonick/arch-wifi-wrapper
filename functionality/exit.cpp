#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

// TODO: is this memory safe? how the fuck do i code an exit button?
void close_app(Fl_Widget* w, void* data) {
    // Flush any pending events/graphics
    Fl::flush();

    // Ensure all FLTK windows are closed and deleted properly
    while (Fl::first_window()) {
        Fl_Window* window = Fl::first_window();
        window->hide();  // Hide window
        Fl::delete_widget(window);  // Delete it properly
    }

    // Ensure all pending events are handled safely
    Fl::awake();

    // Properly exit without leaking memory
    exit(0);
}