#ifndef MAC_H
#define MAC_H

#include <string>

struct parsed_ncmli_list_output
{
    std::string bssid;
    std::string ssid;
    std::string full_output;
    bool include_escape;
};
#endif