#ifndef PARSE_H
#define PARSE_H
#include <string>
#include "../constants/mac.h"

struct network_data_basic 
{
    std::string bssid;
    std::string ssid;
};

// if include_escape is true, will include the forward slashes in original terminal output
parsed_ncmli_list_output parse_nmcli_list_output(std::string line, bool include_escape);
network_data_basic parse_scan_line(const char *);

#endif