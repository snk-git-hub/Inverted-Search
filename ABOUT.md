# About Inverted-Search

**Inverted-Search** is a C-based text-search project that builds an inverted index for words found across multiple text files.

The project demonstrates core information-retrieval concepts, including:

- File validation and input handling
- Word tokenization
- Hash-based indexing
- Linked-list data structures
- Mapping words to the files in which they occur
- Persisting index data for later use

## Purpose

Instead of scanning every document for each search request, an inverted index stores each word together with the files that contain it. This makes word lookups faster and provides a practical introduction to how search engines organize text data.

## Technology

- **Language:** C
- **Build system:** Make
- **Input:** Plain-text files

## Getting Started

Build the project with:

```bash
make
```

Then run it with one or more text files:

```bash
./a.out file1.txt file2.txt
```
