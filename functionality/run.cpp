#include <string>
#include <iostream>
#include <cstring>
#include <errno.h>

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