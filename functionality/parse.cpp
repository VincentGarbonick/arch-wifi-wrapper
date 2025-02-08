#include <string>
#include <iostream>
#include "../constants/mac.h"

// if include_escape is true, will include the forward slashes in original terminal output
// expected input: E8\:D3\:EB\:33\:7B\:03:network_name
parsed_ncmli_list_output parse_nmcli_list_output(std::string line, bool include_escape)
{
    const parsed_ncmli_list_output pm = {
        .full_mac = "fart",
        .network_name = "fart",
        .full_output = "fart fart",
        .include_escape = true,
    };

    // std::vector<std::string> mac_parts;
    // std::istringstream ss(line);
    // std::string mac, part;

    // // Extract the first word (MAC address)
    // ss >> mac;
    
    // // Split by ':'
    // std::istringstream mac_stream(mac);
    // while (std::getline(mac_stream, part, ':')) {
    //     mac_parts.push_back(part);
    // }


    std::cout << line[0] << std::endl;

    // we know what an escaped mac address looks like
    return pm;
}