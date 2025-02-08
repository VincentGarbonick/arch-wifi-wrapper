#ifndef MAC_H
#define MAC_H

#include <string>

struct parsed_mac 
{
    std::string full_mac;
    bool include_escape;
    std::string full_line;
};
#endif