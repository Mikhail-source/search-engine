#include "converter_json.h"

#include <fstream>
#include <nlohmann/json.hpp>
//to do: check .json struct

const std::string PATH = "../";

std::vector<std::string> ConverterJSON::GetTextDocuments(){
    std::vector<std::string> file_content;
    std::ifstream config_file;
    std::ifstream read_file;
    nlohmann::json dict;
    int length;
    char* buffer;

    config_file.open(PATH + "config.json", std::ios::in);
    if(config_file.is_open()){
        config_file >> dict;
        if(dict["config"] == nullptr){
            throw std::runtime_error("ERROR config file is empty");
        } else {
            for(auto& n : dict["files"]){
                read_file.open(n, std::ios::in);
                if(read_file.is_open()){
                    read_file.seekg (0, std::ios::end);
                    length = read_file.tellg();
                    read_file.seekg (0, std::ios::beg);
                    buffer = new char [length];
                    read_file.read(buffer, length);
                    file_content.push_back(buffer);
                } else {
                    throw std::runtime_error("ERROR open file: ");
                }
                read_file.close();
            }
        }
        config_file.close();
    } else {
        throw std::runtime_error("ERROR config file is missing");
    }

    return file_content;
};

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
