#ifndef INC_2D_GAME_SDL2_UTILS_H
#define INC_2D_GAME_SDL2_UTILS_H

#include <cstring>

inline const char *asset(const char *_filename) {
    const char *assetsPath = "../assets/";
    const char *extension = ".png";
    char *filename = new char[std::strlen(assetsPath) + strlen(_filename) + strlen(extension) + 1];
    strcpy(filename, assetsPath);
    strcat(filename, _filename);
    strcat(filename, extension);
    return filename;
}

#endif //INC_2D_GAME_SDL2_UTILS_H
