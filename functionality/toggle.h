#ifndef TOGGLE_H
#define TOGGLE_H

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Output.H>

void toggle_wifi(Fl_Widget*, void*);
void safe_toggle_button_text(std::string, 
							 Fl_Widget *,
							 Fl_Output *,
							 const char *,
							 const char *);
std::string get_wifi_status();
const char * return_wifi_status_label();

#endif
