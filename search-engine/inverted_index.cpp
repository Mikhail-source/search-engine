#include "inverted_index.h"

//Update document base for search
void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs){

    for(auto n : input_docs)
        std::cout << n << std::endl;
};

//number of words in base
std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word){};
