#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

namespace Files{
    vector <string> get_files_list(const char* path);
    vector <string> get_filename_list(const char* path);
    string split_filename(const string& str);
}