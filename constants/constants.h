#ifndef CONSTANTS_H
#define CONSTANTS_H
// app dimensions
inline const int PARENT_WIDTH = 500;
inline const int PARENT_HEIGHT = 500;
inline const int PARENT_MARGIN_X = 10;
inline const int PARENT_MARGIN_Y = 10;
inline const int WIFI_BROWSER_WIDTH = PARENT_WIDTH - 20;
inline const int WIFI_BROWSER_HEIGHT = PARENT_HEIGHT / 2;
inline const int WIFI_BROWSER_OFFSET_X = PARENT_MARGIN_X;
inline const int WIFI_BROWSER_OFFSET_Y = PARENT_MARGIN_Y;
inline const int WIFI_SCAN_BUTTON_WIDTH = 150; 
inline const int WIFI_SCAN_BUTTON_HEIGHT = 30;
inline const int WIFI_SCAN_BUTTON_OFFSET_X = PARENT_MARGIN_X;
inline const int WIFI_SCAN_BUTTON_OFFSET_Y = WIFI_BROWSER_HEIGHT + 20;
// label names
inline const char * APPNAME = "Arch Wifi Wrapper";
inline const char * WIFI_LIST = "Wifi List";
inline const char * WIFI_SCAN = "Scan for Networks";
// commands
inline const char * CMD_SCAN_WIFI = "nmcli --terse --get-values bssid,ssid device wifi list";
#endif