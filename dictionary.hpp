//
// Created by dldms on 11/1/2018.
//

#ifndef LAB6_DICTIONARY_HPP
#define LAB6_DICTIONARY_HPP
#include <iostream>
#include <map>
#include <iterator>
#include <iostream>
#include <fstream>
using namespace std;
class Dictionary {
    private:
        map<string, string> wordList;
        string fileName;
    public:
        Dictionary(string fileName);
        void printDictionary();
        void searchDictionary();
        void addWord();
        void defineWord(string word, string def);


};


#endif //LAB6_DICTIONARY_HPP
