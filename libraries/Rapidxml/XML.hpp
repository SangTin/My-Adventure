#pragma once
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"

using namespace rapidxml;

class XML{
    protected:
        file<char>* xmlFile;
        xml_document<>* mDocument;
        char* mFile;
    public:
        XML(){}

        char* get_file_location(){
            return mFile;
        }

        xml_document<>* get_document(){
            return mDocument;
        }

        bool load(const char* fileLocation){
            mFile = fileLocation;
            xmlFile = new rapidxml::file<>(fileLocation.c_str());
            if (!xmlFile) return false;
            mDocument = new xml_document<>;
            mDocument->parse<0>(xmlFile->data());
        }
};