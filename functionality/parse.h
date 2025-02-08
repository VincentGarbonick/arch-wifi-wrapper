#ifndef PARSE_H
#define PARSE_H
#include "../constants/mac.h"

// if include_escape is true, will include the forward slashes in original terminal output
parsed_mac get_mac(std::string line, bool include_escape);

#endif