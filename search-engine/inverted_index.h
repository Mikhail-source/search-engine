#pragma once

#include <vector>
#include <string>
#include <map>

struct Entry {
    size_t doc_id, count;

    bool operator == (const Entry& other) const {
        return (doc_id == other.doc_id && count == other.count);
    }
};

class InvertedIndex {
public:
    InvertedIndex() = default;

    //Update document base for search
    void UpdateDocumentBase(std::vector<std::string> input_docs);

    //number of words in base
    std::vector<Entry> GetWordCount(const std::string& word);

private:
    //list of document contents
    std::vector<std::string> docs;

    //frequency dictionary
    std::map<std::string, std::vector<Entry>> freq_dictionary;
};
