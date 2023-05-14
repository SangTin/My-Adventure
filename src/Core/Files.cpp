#include <Core/Files.hpp>
#include <filesystem>
#include <sys/stat.h>
#include <iostream>
#include <dirent.h>

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

/**
 * Return a vector of string contains all name of files in the given path
 * \param path the path on the filesystem to get files from
*/
std::vector <std::string> Files::get_filename_list(const char* path){
    DIR *dir_ptr;
    struct dirent *diread;
    vector<string> filenames;
    if ((dir_ptr = opendir(path)) != nullptr) {
        while ((diread = readdir(dir_ptr)) != nullptr) {
            filenames.push_back(diread->d_name);
        }
        closedir(dir_ptr);
    } else {
        perror("fail");
    }
    return filenames;
}

string Files::split_filename(const string& path){
    fs::path f(path);
    return f.stem().string();
}