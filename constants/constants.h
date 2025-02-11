#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
// TODO: Implement namespace for this!
// TODO: Make your y direction for the buttons "row 1, row 2, etc"

// app dimensions
inline const int PARENT_WIDTH = 500;
inline const int PARENT_HEIGHT = 400;
inline const int PARENT_MARGIN_X = 10;
inline const int PARENT_MARGIN_Y = 10;

inline const int GENERAL_Y_MARGIN = 25;
inline const int BUTTON_X_SPACING_MARGIN = 15;

inline const int BUTTON_BASE_WIDTH = 150;
inline const int BUTTON_BASE_HEIGHT = 30;

inline const int WIFI_BROWSER_WIDTH = PARENT_WIDTH - 20;
inline const int WIFI_BROWSER_HEIGHT = 250;
inline const int WIFI_BROWSER_OFFSET_X = PARENT_MARGIN_X;
inline const int WIFI_BROWSER_OFFSET_Y = PARENT_MARGIN_Y;

// info bars
inline const int CURRENT_BAR_WIDTH = WIFI_BROWSER_WIDTH;
inline const int CURRENT_BAR_HEIGHT = 20;
inline const int CURRENT_BAR_OFFSET_X = PARENT_MARGIN_X;
inline const int CURRENT_BAR_OFFSET_Y = WIFI_BROWSER_HEIGHT + GENERAL_Y_MARGIN;

inline const int STATUS_BAR_WIDTH = WIFI_BROWSER_WIDTH;
inline const int STATUS_BAR_HEIGHT = 20;
inline const int STATUS_BAR_OFFSET_X = PARENT_MARGIN_X;
inline const int STATUS_BAR_OFFSET_Y = CURRENT_BAR_OFFSET_Y + GENERAL_Y_MARGIN;

// first row of buttons 
inline const int WIFI_SCAN_BUTTON_WIDTH = BUTTON_BASE_WIDTH; 
inline const int WIFI_SCAN_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int WIFI_SCAN_BUTTON_OFFSET_X = PARENT_MARGIN_X;
inline const int WIFI_SCAN_BUTTON_OFFSET_Y = STATUS_BAR_OFFSET_Y + GENERAL_Y_MARGIN;

inline const int CONNECT_BUTTON_WIDTH = BUTTON_BASE_WIDTH;
inline const int CONNECT_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int CONNECT_BUTTON_OFFSET_X = PARENT_MARGIN_X + BUTTON_BASE_WIDTH + BUTTON_X_SPACING_MARGIN;
inline const int CONNECT_BUTTON_OFFSET_Y = WIFI_SCAN_BUTTON_OFFSET_Y;

inline const int FORGET_BUTTON_WIDTH = BUTTON_BASE_WIDTH;
inline const int FORGET_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int FORGET_BUTTON_OFFSET_X = CONNECT_BUTTON_OFFSET_X + BUTTON_BASE_WIDTH + BUTTON_X_SPACING_MARGIN;
inline const int FORGET_BUTTON_OFFSET_Y = WIFI_SCAN_BUTTON_OFFSET_Y;

//second row of buttons 
inline const int ENABLE_BUTTON_WIDTH = BUTTON_BASE_WIDTH;
inline const int ENABLE_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int ENABLE_BUTTON_OFFSET_X = PARENT_MARGIN_X;
inline const int ENABLE_BUTTON_OFFSET_Y = PARENT_MARGIN_Y + WIFI_SCAN_BUTTON_OFFSET_Y + GENERAL_Y_MARGIN;

inline const int HELP_BUTTON_WIDTH = BUTTON_BASE_WIDTH;
inline const int HELP_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int HELP_BUTTON_OFFSET_X = PARENT_MARGIN_X + BUTTON_BASE_WIDTH + BUTTON_X_SPACING_MARGIN;
inline const int HELP_BUTTON_OFFSET_Y = ENABLE_BUTTON_OFFSET_Y;

inline const int EXIT_BUTTON_WIDTH = BUTTON_BASE_WIDTH;
inline const int EXIT_BUTTON_HEIGHT = BUTTON_BASE_HEIGHT;
inline const int EXIT_BUTTON_OFFSET_X = HELP_BUTTON_OFFSET_X + BUTTON_BASE_WIDTH + BUTTON_X_SPACING_MARGIN;
inline const int EXIT_BUTTON_OFFSET_Y = ENABLE_BUTTON_OFFSET_Y;

// label names
// TOOD: append "LABEL_"
inline const char * APPNAME = "Arch Wifi Wrapper";
inline const char * WIFI_LIST = "Wifi List";
inline const char * WIFI_SCAN = "Scan for Networks";
inline const char * CONNECT = "Connect to Selected";
inline const char * FORGET = "Forget Current Conn";
inline const char * ENABLED_WIFI = "Wifi Enabled";
inline const char * DISABLED_WIFI = "Wifi Disabled";
inline const char * HELP = "Help";
inline const char * EXIT = "Exit";

// commands
inline const char * CMD_SCAN_WIFI = "nmcli --terse --get-values bssid,ssid device wifi list";
inline const char * CMD_WIFI_OFF = "nmcli radio wifi off";
inline const char * CMD_WIFI_ON = "nmcli radio wifi on";
inline const char * CMD_WIFI_CHECK = "nmcli radio wifi";

// positions for mac address
inline const int RAW_MAC_ADDR_START = 0;
inline const int RAW_MAC_ADDR_END = 22;

// output messages
// TODO: append OUTPUT_
inline const char * EXECUTION_ERROR = "Error executing command";
inline const char * SCAN_SUCCESSFUL = "Scan successful!";
inline const char * TOGGLE_ERROR = "Error toggling wifi!";
inline const char * DISABLED_SUCCESSFUL_MESSAGE = "You have disabled the wifi.";
inline const char * ENABLED_SUCCESSFUL_MESSAGE = "You have enabled the wifi.";

// misc 
inline const std::string NMCLI_WIFI_ENABLED = "enabled";
inline const std::string NMCLI_WIFI_DISABLED = "disabled";
#endif