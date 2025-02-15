#ifndef RUN_H
#define RUN_H

#include <string>
#include <FL/Fl_Output.H>
std::string run_command(const std::string&);
std::string run_command(const std::string&, Fl_Output *);
int run_command_get_exit_status(const char *);

#endif