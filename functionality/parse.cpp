#include <string>
#include <iostream>
#include "../constants/mac.h"

// if include_escape is true, will include the forward slashes in original terminal output
parsed_mac get_mac(std::string line, bool include_escape)
{
    const parsed_mac pm = {
        .full_mac = "fart",
        .include_escape = true,
        .full_line = "fart fart"
    };

    std::cout << line[0] << std::endl;

    // we know what an escaped mac address looks like
    return pm;
}