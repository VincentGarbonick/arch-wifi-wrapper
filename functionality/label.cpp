#include "../constants/main_constants.h"
#include "run.h"
#include "toggle.h"

#include <iostream>

namespace label 
{
    // this is for when we first draw the button
    // it just tells us what label to use
    const char * get_wifi_button_label()
    {
		if(get_wifi_status() == NMCLI_WIFI_ENABLED)
		{
			return ENABLED_WIFI;
		}
		else 
		{
			return DISABLED_WIFI;
		}
	}

    std::string get_initial_current_conn_label()
    {
    	if(get_wifi_status() == NMCLI_WIFI_DISABLED)
    	{
    		return NO_WIFI_WIFI_STATUS_BAR;
    	}
    	else 
    	{
			std::string command_output = run_command(CMD_GET_CURRENT_CONN);
			std::string network_name = command_output.substr(0, command_output.size() - 1);
			// cut off last char because it's a newline
    		return CONNECTION_PREFIX + network_name;
    	}
    }

}
