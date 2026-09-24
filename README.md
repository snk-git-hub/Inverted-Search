# Inverted Search

A C-based project for implementing an inverted index to support efficient text search. The goal is to map each word to the list of files where it appears, enabling fast retrieval during search operations.

This project is designed around the core concepts of information retrieval and inverted indexing, with a focus on simple data structures and hash-based lookup strategies.

## Project Overview

An inverted index stores mappings from terms to their locations in a set of documents instead of storing documents for each term. In this repository, the idea is to read text files, validate them, store relevant file references, and build a search structure that can quickly answer which files contain a given word.

The project is inspired by the following concepts:

- Forward indexing
- Inverted indices
- Hash-based organization of terms
- File validation for text documents
- Linked list based storage

## Why This Project

Inverted indexes are widely used in search engines and document retrieval systems because they allow efficient lookups for words across large collections of files. Instead of scanning every document for every query, an inverted index stores a reverse map from each term to the files that contain it.

## Repository Structure

- `main.c` – entry point of the program
- `header.h` – shared declarations and structures
- `validate.c` – file validation and insertion logic
- `database.c` – database-related functionality
- `database.h` – database declarations
- `fileList.c` and `fileList.h` – file list handling
- `string_token.c` – tokenization logic for words
- `write_database_file.c` – writing index/database data to files
- `Makefile` – build configuration for compiling the project
- `file1.txt` and `file2.txt` – sample input files used for testing

## Build Instructions

Compile the project using the provided Makefile:

```bash
make
```

This creates the executable `a.out`.

## Run the Program

You can run the program with text files as arguments:

```bash
./a.out file1.txt file2.txt
```

The program validates the input files and prepares them for indexing and search operations.

## Example Use Case

If the input files contain text such as:

- `file1.txt`: "apple banana apple"
- `file2.txt`: "banana orange"

Then the inverted index would represent information similar to:

- `apple` -> `file1.txt`
- `banana` -> `file1.txt`, `file2.txt`
- `orange` -> `file2.txt`

This allows the system to quickly find which files contain a given word.

## Current Status

This repository contains the foundation for an inverted search implementation in C. It includes data structure prototypes, file validation logic, and build support. Further development may include complete tokenization, hash indexing, file parsing, and query processing.

## Future Enhancements

- Full word extraction and tokenization
- Hash table based indexing
- Duplicate handling for repeated words
- Frequency and position tracking
- Search queries for single or multiple terms
- Output of matching documents for each query

## License

This project does not currently include a license file. If you plan to distribute or use the project publicly, you may want to add an appropriate open-source license.
