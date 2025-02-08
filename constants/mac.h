#ifndef MAC_H
#define MAC_H

#include <string>

struct parsed_ncmli_list_output
{
    std::string full_mac;
    std::string network_name;
    std::string full_output;
    bool include_escape;
};
#endif