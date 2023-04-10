// This cpp file calls the searchEngine function
// Author : Mohammed Hisham Moizuddin

#include <iostream>
#include "search.h"
#include <sstream>
#include <map>
using namespace std;

int main() {
    string filename;
    getline(cin, filename, '\n');
    searchEngine(filename);
    return 0;
}
