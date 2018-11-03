#include "dictionary.hpp"


Dictionary::Dictionary(string file) {
    fileName = file;
    ifstream ifile(fileName, ios::in);

    if (!ifile.is_open()) {
        cerr << "There was a problem opening the input file!\n";
        exit(1);
    }

    int count = 0;
    string temp = "";
    string word = "";
    string def = "";
    while (getline(ifile, temp)) {
        if(count % 2 == 0) {
            word = temp;
        }else {
            def = temp;
            if (word.substr(word.length() - 1, word.length()) == "\r") {
                word = word.substr(0, word.length() - 1);
            }
            if (def.substr(def.length() - 1, def.length()) == "\r") {
                def = def.substr(0, def.length() - 1);
            }
            wordList.insert(make_pair(word, def));
        }
        count++;
    }
}

void Dictionary::printDictionary() {

    for(multimap<string, string>::iterator oneNumber = wordList.begin();
        oneNumber != wordList.end(); ++oneNumber)
    {
        cout << oneNumber->first << " - " << oneNumber->second << endl;
    }

}

void Dictionary::searchDictionary() {
    ifstream ifile(fileName, ios::in);

    if (!ifile.is_open()) {
        cerr << "There was a problem opening the input file!\n";
        exit(1);
    }

    int count = 0;
    string temp = "";
    string word = "";
    string def = "";
    while (getline(ifile, temp)) {
        if(count % 2 == 0) {
            word = temp;
        }else {
            def = temp;
            if (word.substr(word.length() - 1, word.length()) == "\r") {
                word = word.substr(0, word.length() - 1);
            }
            if (def.substr(def.length() - 1, def.length()) == "\r") {
                def = def.substr(0, def.length() - 1);
            }
            wordList.insert(make_pair(word, def));
        }
        count++;
    }
    cin.ignore();
    cout<<"Enter to search word definition"<<endl;
    getline (cin,temp);
    multimap<string, string>::iterator oneNumber = wordList.find(temp);
    if (oneNumber == wordList.end()) {
        cout << "No word found : " << temp << "..?"<<endl;
    } else {
        cout << "Definition of " << oneNumber->first << ": \n" << oneNumber->second;
    }
}

void Dictionary::addWord() {
    cin.ignore();
    string temp;
    string def;
    cout<<"Enter a word to add"<<endl;
    getline (cin,temp);
    multimap<string, string>::iterator oneNumber = wordList.find(temp);
    if (oneNumber == wordList.end()) {
        cout << "You are trying to add the word, " << temp << ","<<endl;
        cout<<"Enter the definition of the word :";
        getline (cin,def);
        defineWord(temp, def);
        cout<<"\nWord " << temp << " is added to the dictionary"<<endl;

    } else {
        cout << "The word already exists, no need to add them.";
    }
}

void Dictionary::defineWord(string word, string def) {
    fstream myfile;
    myfile.open ("../dictionary.txt");
    myfile.seekp (0, ios::end);
    myfile << "\n" << word << "\n" << def;
    myfile.close();
}