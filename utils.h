#pragma once

#include <cstring>

inline const char *asset(const char *_filename) {
    const char *assetsPath = "../assets/";
    const char *extension = ".png";
    char *filename = new char[std::strlen(assetsPath) + strlen(_filename) + strlen(extension) + 1];
//    Prefix the asset name with the assets directory path
    strcpy(filename, assetsPath);
    strcat(filename, _filename);
//    Append .png at the end of the filepath 
    strcat(filename, extension);
    return filename;
}