#include "inverted_index.h"

#include <fstream>
#include <iostream>
#include <sstream>

//Update document base for search
void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs){
    std::ifstream read_file;
    std::stringstream ss;

    for(auto& n : input_docs){
        read_file.open(n, std::ios::in);
        if(read_file.is_open()){
            ss << read_file.rdbuf();
            docs.push_back(ss.str());
        } else {
            throw std::runtime_error("ERROR open file: " + n);
        }
    }
};

//number of words in base
std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word){
    std::vector<Entry> result;


};
