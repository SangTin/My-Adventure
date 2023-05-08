#include <Core/Files.hpp>
#include <filesystem>
#include <sys/stat.h>
#include <iostream>

namespace fs = std::filesystem;

/**
 * Return a vector of string contains all files in the given path
 * \param path the path on the filesystem to get files from
*/
std::vector <std::string> Files::get_files_list(const char* path){
    std::vector<std::string> res;
    // This structure would distinguish a file from a directory
    struct stat sb;
 
    // Looping until all the items of the directory are exhausted
    for (const auto& entry : fs::directory_iterator(path)) {
        std::filesystem::path fileName = entry.path();
        std::string path = fileName.string();
 
        // Testing whether the path points to a non-directory or not 
        // If it does, record path
        if (stat(path.c_str(), &sb) == 0 && !(sb.st_mode & S_IFDIR))
            res.emplace_back(path);
    }
    return res;
}