#include "converter_json.h"

//to do: check .json struct

const std::string PATH = "../";

//Get list of files from config.json
std::vector<std::string> ConverterJSON::GetTextDocuments(){
    std::vector<std::string> result;
    std::ifstream read_file;
    nlohmann::json dict;

    read_file.open(PATH + "config.json", std::ios::in);
    if(read_file.is_open()){
        read_file >> dict;
        if(dict["config"] != nullptr){
            for(auto& n : dict["files"]){
                result.push_back(n);
            }
        } else {
            throw std::runtime_error("ERROR config file is empty");
        }
        read_file.close();
    } else {
        throw std::runtime_error("ERROR config file is missing");
    }

    return result;
};

//Get max_responses from config.json
int ConverterJSON::GetResponsesLimit(){
    int result;
    std::ifstream read_file;
    nlohmann::json dict;


    read_file.open(PATH + "config.json", std::ios::in);
    if(read_file.is_open()){
        read_file >> dict;
        if(dict["config"] != nullptr){
            result = dict["config"]["max_responses"];
        } else {
            throw std::runtime_error("ERROR config file is empty");
        }
        read_file.close();
    } else {
        throw std::runtime_error("ERROR config file is missing");
    }

    return result;
};

//Get list of requests from requests.json
std::vector<std::string> ConverterJSON::GetRequests(){
    std::vector<std::string> result;
    std::ifstream read_file;
    nlohmann::json dict;


    read_file.open(PATH + "requests.json", std::ios::in);
    if(read_file.is_open()){
        read_file >> dict;
        for(auto& n : dict["requests"]){
            result.push_back(n);
        }
        read_file.close();
    } else {
        throw std::runtime_error("ERROR config file is missing");
    }

    return result;
};

//Put result in answers.json
void ConverterJSON::putAnswers(std::vector<std::vector<std::pair<int, float>>>answers){
    std::ofstream write_file;
    nlohmann::json dict = answers;

    write_file.open(PATH + "answers.json", std::ios::out);
    if(write_file.is_open()){
        write_file << dict;
        write_file.close();
    } else {
        throw std::runtime_error("ERROR config file is missing");
    }
};
