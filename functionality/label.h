#ifndef LABEL_H
#define LABEL_H

#include <string>

namespace label 
{
    std::string get_wifi_connection_ssid_label();
    std::string get_wifi_connection_ssid_label_toggle();
    const char * get_wifi_radio_label();
}

#endif