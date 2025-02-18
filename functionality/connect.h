#ifndef CONNECT_H
#define CONNECT_H

#include <string>

using std::string;

namespace connect
{
    struct network_data {
        string bssid;
        string ssid;
    };

    string get_current_conn_label()
    {

    }
}

#endif