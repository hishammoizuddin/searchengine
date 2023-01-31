// This cpp file calls the searchEngine function
// Author : Mohammed Hisham Moizuddin
// CS 251 - Project 2 - Search Engine
#include <iostream>
#include "search.h"
#include <sstream>
#include <map>
using namespace std;

int main() {
    string filename;
    getline(cin, filename, '\n');
    searchEngine(filename);
// map <string, set<string>> myData;
// int x = buildIndex("tiny.txt", myData);

// for (auto e : myData) {
//     cout<<e.first<<" -> ";
//     for (auto d: e.second) {
//         cout<<d<<", ";
//     }
//     cout<<endl;
// }
    return 0;
}