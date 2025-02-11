#ifndef CALLBACK_DATA_H
#define CALLBACK_DATA_H

#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Output.H>

struct scan_args 
{
    Fl_Select_Browser * browser;
    Fl_Output * output;
};

#endif