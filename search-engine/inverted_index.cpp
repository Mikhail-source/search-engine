#include "inverted_index.h"

#include <fstream>
#include <cctype>

//Update document base for search
void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs){
    std::ifstream read_file;
    int length;
    char* buffer;

    for(auto& n : input_docs){
        read_file.open(n, std::ios::in);
        if(read_file.is_open()){
            read_file.seekg (0, std::ios::end);
            length = read_file.tellg();
            read_file.seekg (0, std::ios::beg);
            buffer = new char [length];
            read_file.read(buffer, length);
            docs.push_back(buffer);
        } else {
            throw std::runtime_error("ERROR open file: " + n);
        }
        read_file.close();
    }
};

//number of words in base
std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word){
    std::vector<Entry> result;
    std::string stringBuffer = "";

    for(size_t i=0; i<docs.size(); i++){
        for(auto& k : docs[i]){
            if(std::isalpha(k) || k == '\''){
                stringBuffer += std::tolower(k);
            } else {
                if(word == stringBuffer){
                    if(result.size() != 0){
                        if(result.back().doc_id == i){
                            result.back().count++;
                        } else {
                            result.push_back({i, 1});
                        }
                    } else {
                        result.push_back({i, 1});
                    }
                }
                stringBuffer = "";
            }
        }
    }

    return result;
};
