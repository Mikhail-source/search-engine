#include "inverted_index.h"
#include "converter_json.h"

int main(int argc, char *argv[]){
    InvertedIndex invert;
    ConverterJSON convert;

    invert.UpdateDocumentBase(convert.GetTextDocuments());

    return 0;
}
