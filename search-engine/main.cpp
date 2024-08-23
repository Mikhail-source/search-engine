#include "inverted_index.h"
#include "converter_json.h"
#include "searchserver.h"

int main(int argc, char *argv[]){
    ConverterJSON converter;
    InvertedIndex inverter;
    SearchServer searcher(inverter);

    inverter.UpdateDocumentBase(converter.GetTextDocuments());


    return 0;
}
