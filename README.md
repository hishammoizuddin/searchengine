# Search Engine Optimization

A simple search engine implementation in C++ that uses inverted indexing to efficiently search through text data. The project demonstrates skills in data processing, file I/O, data structures, and algorithms.

## Overview

The search engine project consists of three main components:

1. A header file `search.h` containing the search engine implementation with several functions for processing and searching data.
2. A `main.cpp` file that calls the search engine function and provides a user interface to interact with the search engine.
3. A Makefile to compile and run the program.

The search engine uses an inverted index data structure to organize the data and enable efficient search. It processes text data from a file, tokenizes it, and indexes it in a map data structure. The user can then provide search queries to find matching URLs.

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

`make run`

4. (Optional) If you want to clean the build files:

`make clean`

5. (Optional) If you want to check for memory leaks with Valgrind:

`make valgrind`


## Usage

1. When you run the program, it will prompt you to enter the data file name. Provide the name of a text file containing the data to be processed by the search engine.
2. The program will build an index and display the number of indexed pages and unique terms.
3. Enter a query sentence to search for matching URLs. You can use "+" or "-" before a term to include or exclude it from the search results.
4. Press Enter to quit the program.







