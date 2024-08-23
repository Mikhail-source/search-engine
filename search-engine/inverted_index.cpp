#include "inverted_index.h"

#include <cctype>
#include <thread>


void InvertedIndex::UpdateDocumentBase(std::vector<std::string> input_docs){
    std::string stringBuffer = "";
    std::vector<std::thread> indexThread;
    docs = input_docs;

    for(size_t i = 0; i < docs.size(); i++){
        for(auto& k : docs[i]){
            if(std::isalpha(k) || k == '\''){
                stringBuffer += std::tolower(k);
            } else {
                if(freq_dictionary.find(stringBuffer) == freq_dictionary.end() & stringBuffer != ""){
                    freq_dictionary.insert(std::pair<std::string, std::vector<Entry>>(stringBuffer, GetWordCount(stringBuffer)));
                }
                stringBuffer = "";
            }
        }
    }
};

std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word){
    std::vector<Entry> result = {};
    std::string stringBuffer = "";

    if(freq_dictionary.find(word) == freq_dictionary.end()){
        for(size_t i = 0; i < docs.size(); i++){
            for(auto& k : docs[i]){
                if(std::isalpha(k) || k == '\''){
                    stringBuffer += std::tolower(k);
                } else {
                    if(stringBuffer == word){
                        if(result.size() == 0){
                            result.push_back({0, 1});
                        } else {
                            if(result.back().doc_id == i){
                                result.back().count++;
                            } else {
                                result.push_back({i, 1});
                            }
                        }
                    }
                    stringBuffer = "";
                }
            }
        }
    }

    return result;
}
