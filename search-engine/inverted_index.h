#pragma once

#include <vector>
#include <string>
#include <map>

#include "gtest/gtest.h"


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

/*void TestInvertedIndexFunctionality(const std::vector<std::string>& docs,
                                    const std::vector<std::string>& requests,
                                    const std::vector<std::vector<Entry>>& expected){
    std::vector<std::vector<Entry>> result;
    InvertedIndex idx;

    idx.UpdateDocumentBase(docs);
    for(auto& request : requests){
        std::vector<Entry> word_count = idx.GetWordCount(request);
        result.push_back(word_count);
    }
    ASSERT_EQ(result, expected);
}

TEST(TestCaseInvertedIndex, TestBasic){
    const std::vector<std::string> docs = {
        "london is the capital of great britain",
        "big ben is the nickname for the Great bell of the striking clock"};
    const std::vector<std::string> requests = {"london", "the"};
    const std::vector<std::vector<Entry>> expected = {
                                                        {
                                                            {0, 1}
                                                        },
                                                        {
                                                            {0, 1}, {1, 3}
                                                        }
                                                     };
    TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseInvertedIndex, TestBasic2){
    const std::vector<std::string> docs = {
        "milk milk milk milk water water water",
        "milk water water",
        "milk milk milk milk milk water water water water water",
        "americano cappuccino"};
    const std::vector<std::string> requests = {"milk", "water", "cappuchino"};
    const std::vector<std::vector<Entry>> expected = {
                                                        {
                                                            {0, 4}, {1, 1}, {2, 5}
                                                        },
                                                        {
                                                            {0, 2}, {1, 2}, {2, 5}
                                                        },
                                                        {
                                                            {3, 1}
                                                        }
                                                     };
    TestInvertedIndexFunctionality(docs, requests, expected);
}

TEST(TestCaseInvertedIndex, TestInvertedIndexMissingWord){
    const std::vector<std::string> docs = {"a b c d e f g h i j k l", "statement"};
    const std::vector<std::string> requests = {"m", "statement"};
    const std::vector<std::vector<Entry>> expected = {
                                                        {},
                                                        {
                                                            {1, 1}
                                                        }
                                                     };
    TestInvertedIndexFunctionality(docs, requests, expected);
}*/
