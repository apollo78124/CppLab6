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
        /**
         * Map to store the word and the definitions.
         */
        map<string, string> wordList;

        /**
         * String initialized when contructed.
         * Contains the file directory.
         */
        string fileName;
    public:
        /**
         * Constructor initializing filedirectory.
         * @param fileName
         */
        Dictionary(string fileName);

        /**
         * Print the whole dictionary.
         */
        void printDictionary();

        /**
         * Search the specific word.
         */
        void searchDictionary();

        /**
         * Add the word.
         */
        void addWord();

        /**
         * Add the added word in the addWord method to the text file.
         */
        void defineWord(string word, string def);


};


#endif //LAB6_DICTIONARY_HPP
