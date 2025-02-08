#include <string>
#include <iostream>
#include <algorithm>
#include "../constants/mac.h"
#include "../constants/constants.h"

// if include_escape is true, will include the forward slashes in original terminal output
// expected input: E8\:D3\:EB\:33\:7B\:03:network_name
parsed_ncmli_list_output parse_nmcli_list_output(std::string line, bool include_escape)
{
    // our line will always look the same, so we can directly index
    // MAC portion is 0-21 inclusive
    std::string mac_component = line.substr(MAC_ADDR_START, MAC_ADDR_END); 
    std::string network_name_component = line.substr(23);

    if(include_escape == false)
    {
        mac_component.erase(std::remove(mac_component.begin(), 
                                        mac_component.end(), '\\'), 
                                        mac_component.end());
    }

    return {
        .full_mac = mac_component,
        .network_name = network_name_component,
        .full_output = line,
        .include_escape = include_escape,
    };
}