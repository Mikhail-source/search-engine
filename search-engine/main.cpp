#include "inverted_index.h"
#include "converter_json.h"

#include <iostream>

int main(int argc, char *argv[]){
    ConverterJSON converter;
    InvertedIndex inverter;

    std::map<std::string, std::vector<Entry>> test;

    inverter.UpdateDocumentBase(converter.GetTextDocuments());

    for(auto& n : converter.GetRequests()){
        test.insert({n, inverter.GetWordCount(n)});
    }

    for(auto& n : test){
        std::cout << n.first << " ";
        for(auto& k : n.second){
            std::cout << "(" << k.doc_id << ", " << k.count << ")";
        }
        std::cout << std::endl;
    }

    return 0;
}
