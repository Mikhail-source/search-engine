#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

class ConverterJSON {
public:
    ConverterJSON() = default;

    std::vector<std::string> GetTextDocuments();

    int GetResponsesLimit();

    std::vector<std::string> GetRequests();

    void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);

    void test();
};
