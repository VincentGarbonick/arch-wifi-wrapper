#include <string>
#include <iostream>
#include "main_constants.h"

std::string CONCAT_CMD_CHECK_STORED_CONN(std::string bssid, std::string ssid)
{
    std::string full_command =  CMD_CHECK_STORED_CONN_1 +
                                "'" + bssid + ":" + ssid + "'" +
                                CMD_CHECK_STORED_CONN_2;
    std::cout << full_command << std::endl;
    return "fart";
}