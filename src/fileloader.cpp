#include "FileLoader.hpp"

#include <iostream>
#include <fstream>
#include <string>
void FileLoader::loadGrid(const std::string& path) {
    char tile;
    std::fstream  mapFile;
    mapFile.open(path);

    mapFile.close();
}
