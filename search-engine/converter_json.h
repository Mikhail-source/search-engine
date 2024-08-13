#pragma once

#include <vector>
#include <string>

class ConverterJSON {
public:
    ConverterJSON() = default;

    //Get content of files from config.json
    std::vector<std::string> GetTextDocuments();

    //Get max_responses from config.json
    int GetResponsesLimit();

    //Get list of requests from requests.json
    std::vector<std::string> GetRequests();

    //Put result in answers.json
    void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);
};
