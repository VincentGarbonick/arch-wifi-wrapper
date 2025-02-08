#ifndef MAC_H
#define MAC_H

#include <string>

struct parsed_mac 
{
    int start_pos;
    int end_pos;
    std::string full_mac;
    bool include_escape;
    std::string full_line;
};
#endif