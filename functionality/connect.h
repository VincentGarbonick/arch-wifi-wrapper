#ifndef CONNECT_H
#define CONNECT_H

#include <string>
#include "./parse.h"

using std::string;

namespace connect
{

    // you're also gonna need a function to pull the actual data from the box as well
    // a "scan line" is an entry that we have from the big scan network box.
    // we must parse BSSID and SSID to proceed 
    // connect::network_data parse_scan_line(const char *); 

    // string get_current_conn_label()
    // {

    // };
    bool has_connection_stored(network_data_basic);

}

#endif