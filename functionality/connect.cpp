#include <string> 
#include <iostream>
#include "../constants/main_constants.h"
#include "connect.h"
#include "./parse.h"
#include "./run.h"

namespace connect {
    // connect::network_data parse_scan_line(const char * browser_entry) 
    // {
    //     std::cout << browser_entry << std::endl;
    //     return {
    //         .bssid = "hello",
    //         .ssid = "world",
    //     };
    // }
    bool has_connection_stored(network_data_basic network_info)
    {
        const std::string return_value = run_command(
            CONCAT_CMD_CHECK_STORED_CONN(
            network_info.bssid,
            network_info.ssid
            )
        );
        const int integer_result = std::stoi(return_value);
        if(integer_result == STATUS_CHECK_HAS_CONN_STORED)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
}