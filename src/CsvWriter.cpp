#include "CsvWriter.hpp"

#include <iostream>
#include <stdexcept>
#include <fstream>

CsvWriter::CsvWriter(std::vector<std::string> columns, std::string fileName, std::string filePath)
:columns_{columns}, numberOfColumns_{columns.size()}, fileName_{fileName},filePath_{filePath}
{
    if(columns.size() < 0){
        throw std::invalid_argument("CSV cannot have less than one column");
    }
    file_.open(filePath_+fileName_+".csv");
    writeData(columns);
}

void CsvWriter::writeData(std::vector<std::string> data){
    int columnIndex = 0;
    if(data.size() != columns_.size()){
        throw std::invalid_argument("Data stream cannot have less data than columns");
    }

    if(file_.is_open()){
        for(std::string dataCol : data){
            file_ << dataCol;
            if(columnIndex < numberOfColumns_){
                file_ << ",";
            }
        }
        file_ << std::endl;
    }
}

void CsvWriter::endWrite(){
    file_.close();
}
