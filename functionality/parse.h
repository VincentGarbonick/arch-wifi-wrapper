#ifndef PARSE_H
#define PARSE_H
#include "../constants/mac.h"

// if include_escape is true, will include the forward slashes in original terminal output
parsed_ncmli_list_output parse_nmcli_list_output(std::string line, bool include_escape);

#endif