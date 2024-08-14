#include "inverted_index.h"
#include "converter_json.h"

#include <iostream>

int main(int argc, char *argv[]){
    ConverterJSON converter;
    InvertedIndex inverter;

    inverter.UpdateDocumentBase(converter.GetTextDocuments());


    return 0;
}
