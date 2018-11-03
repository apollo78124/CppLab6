#include <iostream>
#include <map>
#include <iterator>
#include "dictionary.cpp"

using namespace std;

int main() {
    int input = 0;

    Dictionary d("../dictionary.txt");

  while(true) {
      cout<<"\n(Dictionary Menu) 1:Print 2:Search 3:Add 4:Quit"<<endl;
      cin>>input;
      switch(input) {
          case 1 : d.printDictionary();
                    break;
          case 2 : d.searchDictionary();
              break;
          case 3 : d.addWord();
              break;
          case 4 : cout<<"Quitting Program...\n";
                    return 0;
      }
  }
    return 0;
}