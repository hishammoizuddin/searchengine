# Search Engine Optimization

The search engine optimizer is a console-based C++ implementation that leverages the concept of inverted indexing for efficient text search. It reads and processes data from a text file and provides a user interface to interact with the search engine. The primary purpose of this project is to demonstrate competency in data processing, file I/O, data structures, and algorithms.

*Inverted index* is a data structure that stores a mapping from words or terms to their locations in a set of documents. It allows for fast and efficient search, as it enables the search engine to quickly find documents containing a specific term without scanning through the entire text. In this project, an inverted index is represented using a C++ std::map with std::string keys and std::set values, where the key is a term and the value is a set of URLs containing that term.

## Overview

The search engine project consists of three main components:

1. A header file `search.h` containing the search engine implementation with several functions for processing and searching data.
2. A `main.cpp` file that calls the search engine function and provides a user interface to interact with the search engine.
3. A Makefile to compile and run the program.

The search engine uses an inverted index data structure to organize the data and enable efficient search. It processes text data from a file, tokenizes it, and indexes it in a map data structure. The user can then provide search queries to find matching URLs.

<img src="https://user-images.githubusercontent.com/78191578/230955575-f4a1389f-b1c9-4121-b354-20330341f5ec.gif" width=60% height=60%>

The project showcases skills in:

- Inverted indexing
- Web crawling
- Data processing
- Text manipulation
- File I/O
- Data structures (map, set, stringstream)
- Algorithms (set_intersection)
- C++11 features
- Makefile for building and running the program

## How to Build and Run

To build and run the program, follow these steps:

1. Clone the GitHub repository to your local machine:

`git clone https://github.com/yourusername/your-repository.git`
`cd your-repository`

2. Compile the program:

`make build`

3. Run the program:

`make run` or `./program.exe`

4. (Optional) If you want to clean the build files:

`make clean`

5. (Optional) If you want to check for memory leaks with Valgrind:

`make valgrind`


## Usage

1. When you run the program, it will prompt you to enter the data file name. Provide the name of a text file containing the data to be processed by the search engine.
2. The program will build an index and display the number of indexed pages and unique terms.
3. Enter a query sentence to search for matching URLs. You can use "+" or "-" before a term to include or exclude it from the search results.
4. Press Enter to quit the program.
