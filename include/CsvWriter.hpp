#pragma once

#include <string>
#include <vector>
#include <fstream>

class CsvWriter{
    private:
        std::string filePath_{"./"};
        std::string fileName_{"NewFile"};
        std::ofstream file_{};

        std::vector<std::string> columns_{};
        std::size_t numberOfColumns_{1};

    public:
        CsvWriter(std::vector<std::string> columns, std::string fileName, std::string filePath);
        CsvWriter(std::vector<std::string> columns, std::string fileName) : CsvWriter(columns,fileName,"./") {}
        CsvWriter(std::vector<std::string> columns) : CsvWriter(columns,"NewFile","./") {}

        void writeData(std::vector<std::string> data);
        void endWrite();
};