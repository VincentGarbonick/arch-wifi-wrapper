#include <string>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <FL/Fl_Output.H>
#include "../constants/main_constants.h"

// https://cplusplus.com/forum/beginner/176747/
std::string run_command(const std::string& command)
{
    char psBuffer[256];
    FILE*   pPipe;
    std::string result;

    if ((pPipe = popen(command.c_str(), "r")) == NULL) {
        std::cerr << "Cannot start command: " << strerror(errno) << std::endl;
        return "";
    }
    while (fgets(psBuffer, sizeof(psBuffer), pPipe) != NULL)
        result += psBuffer;

    if(!feof(pPipe))
        std::cerr << "Error executing command\n";

    pclose(pPipe);
    return result;
}

// TODO: you can use exit status of bash commands!
// TODO: test this by making a command that explicitly errors out to see if things output properly
std::string run_command(const std::string& command, Fl_Output * output)
{
    char psBuffer[256];
    FILE*   pPipe;
    std::string result;
    if ((pPipe = popen(command.c_str(), "r")) == NULL) {
        std::cerr << "Cannot start command: " << strerror(errno) << std::endl;
        output->value(strerror(errno));
        output->redraw();
        return "";
    }
    while (fgets(psBuffer, sizeof(psBuffer), pPipe) != NULL)
        result += psBuffer;

    if(!feof(pPipe))
    {
        std::cerr << EXECUTION_ERROR << "\n";
        output->value(EXECUTION_ERROR);
        output->redraw();
        return "";
    }

    pclose(pPipe);
    return result;
}