/* This header file consists of functions encapsulating all search 
    Search Engine functionalities together */
// Author : Mohammed Hisham Moizuddin
// Search Engine

#pragma once
#include <iostream>
#include <set>
#include <map>
#include <cctype>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

/* This function accepts a string parameter and returns a cleaned version 
    of the string. */
string cleanToken(string s) {
    int begCount = 0, flag = 0;
    string cleanedStr;
    // Finding punctuations from the beginning of the string
    for (int i = 0; i < (int)s.size(); ++i) {
        if (ispunct(s[i])) {
            begCount++;
        } else {
            break;
        }
    }
    cleanedStr = s.substr(begCount, (int)s.size() - begCount + 1);
    // Finding and removing punctuations from the end of the string
    for (int j = cleanedStr.size() - 1; j >= 0; --j) {
       if (ispunct(cleanedStr[j])) {
           cleanedStr.pop_back();
       } else {
            break;
       }
    }
    // Checking if string contains atleast one alphabet
    for (int i = 0; i < (int)cleanedStr.size(); ++i) {
        if (isalpha(cleanedStr[i])) {
            flag = 1;
            break;
        }
    }
    // Converting cleaned string to lowercase
    for (int j = 0; j < (int)cleanedStr.size(); ++j) {
        cleanedStr[j] = tolower(cleanedStr[j]);
    }
    if (flag == 1) {
        return cleanedStr;
    } else {
        return "";
    }
}

/* This Function accepts an entire sentence as a parameter and returns
    a set containing individual and cleaned tokens */
set<string> gatherTokens(string text) {
    set<string> tokens;
    stringstream myStream(text);
    string tempStr, myToken;
    while (myStream >> tempStr) {
        // Cleaning string before gathering into the set
        myToken = cleanToken(tempStr);
        // only inserts strings which are not empty into the set tokens
        if (myToken != "") {
            tokens.insert(myToken);
        }
    }
    return tokens;
}

/* This function processes data from the data file and fills in the map
    with all the data, and also returns the number of pages indexed */
int buildIndex(string filename, map<string, set<string> >& index) {
    string textLine, url;
    int counter = 0;    // To keep track of pages indexed
    ifstream inFile;
    inFile.open(filename);
    while (!inFile.eof()) {
        set<string> tokens;
        // Getting the first line in the file, i.e, the URL
        getline(inFile, url, '\n');
        if (url == "") {
            break;
        }
        /* Getting the second line, i.e, the text which is to be
        cleaned and gathered */
        getline(inFile, textLine, '\n');
        tokens = gatherTokens(textLine);
        // Filling the data inside the map
        for (auto e : tokens) {
            index[e].insert(url);
        }
        counter++;
    }
    return counter;
}

/* This function finds matches to user's queries and returns string set of urls 
    matching the query */
set<string> findQueryMatches(map<string, set<string> >& index, string sentence) {
    set<string> result, unionedSet, tempSet;
    stringstream myStream(sentence);
    string word;
    while (myStream >> word) {
        if (word[0] != '+' && word[0] != '-') {
            string cleanWord = cleanToken(word);
/* Finds mathing URLs in the map and inserts into the result, i.e, union. */
            for (auto url : index[cleanWord]) {
                if (index.count(cleanWord) == 1) {
                    result.insert(url);
                }
            }
        } else if (word[0] == '+') {
            string cleanWord = cleanToken(word);
            set <string> intersectedSet;
            tempSet.clear();
/* Finds matching URLs and inserts into tempSet */
            for (auto url : index[cleanWord]) {
                if (index.count(cleanWord) == 1) {
                    tempSet.insert(url);
                }
            }
/* Finding the intersection of existing result and tempSet */
        set_intersection(result.begin(), result.end(), tempSet.begin(),
            tempSet.end(), std::inserter(intersectedSet, intersectedSet.begin()));
            result = intersectedSet;    // Updating the result
        } else if (word[0] == '-') {
            tempSet.clear();
            string cleanWord = cleanToken(word);
/* Finding matching URLs and erasing them from result (for set difference) */
            for (auto url : index[cleanWord]) {
                if (index.count(cleanWord) == 1) {
                    result.erase(url);
                }
            }
        }
     }
    return result;
}

/* This function organizes all the previously built functionalities in 
    one place efficiently */
void searchEngine(string filename) {
    map<string, set<string> > data;
    set<string> searchResults;
    // Number of Pages indexed
    int pages = buildIndex(filename, data);
    string userInput;
    cout << "Stand by while building index..." << endl;
    cout << "Indexed " << pages << " pages containing " << data.size()
         << " unique terms"   << endl << endl
         << "Enter query sentence (press enter to quit): ";
    getline(cin, userInput, '\n');
    while (userInput != "\n") {
        searchResults = findQueryMatches(data, userInput);
        cout << "Found " << searchResults.size() << " matching pages" << endl;
        for (auto e : searchResults) {
            cout << e << endl;
        }
        cout << endl;
        cout << "Enter query sentence (press enter to quit): ";
        getline(cin, userInput, '\n');
        // Exitting program when user presses enter key
        if (userInput == "") {
        cout << "Thank you for searching!";
        exit(0);
        }
    }
}
