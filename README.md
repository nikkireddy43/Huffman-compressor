```markdown
# Huffman-compressor

A modular C++11 tool to compress and decompress text files using the Huffman coding algorithm. This utility reduces file size by encoding frequently occurring characters with shorter binary codes and supports exact reconstruction of the original content.

---

## Project Structure
Huffman-compressor/
├── headerfiles/                   # Header declarations for all classes
│   ├── node.h                     # Defines the Node class used in the Huffman tree
│   ├── huffman_coder.h            # Declares HuffmanCoder class (encode/decode logic)
│   ├── huffman_util.h             # Declares utility functions for saving/loading code map
│   └── freq_counter.h             # Declares class to count character frequencies from a file
│
├── source/                        # Implementation of all functionalities
│   ├── main.cpp                   # Entry point: handles user interaction and file paths
│   ├── node.cpp                   # Implementation of Node class methods
│   ├── huffman_coder.cpp          # Implements Huffman tree building, encoding, decoding
│   ├── huffman_util.cpp           # Implements saving/loading the Huffman code map
│   └── freq_counter.cpp           # Implements reading text and counting character frequency
│
├── example/                       # Test input/output and resources
│   ├── input.txt                  # Example input text file to compress
│   ├── comp.bin                   # Compressed binary output
│   ├── mp.txt                     # Generated Huffman code map used for decoding
│   ├── output.txt                 # Final decoded text, should match original
│   └── terminal.png               
│
├── README.md                      # This file – project documentation
└── LICENSE, .gitignore 

---

## Features

- Builds Huffman tree from character frequencies
- Compresses text into binary format
- Decompresses binary file back to original text
- Supports saving and loading of Huffman code maps
- Fully modular and written in standard C++11

---

## Build Instructions

Use any C++11-compatible compiler:

```bash
g++ -std=c++11 source/*.cpp -o huffman
````

---

## How to Run

1. **Run the program** from terminal or command prompt:

```bash
./huffman
```

2. **Follow the on-screen prompts** depending on the option:

### compression

```
Enter option (1 = compress, 2 = decompress): 1
Enter input file path to compress: input.txt
Enter path to save map file: mp.txt
Enter path to save compressed binary file: comp.bin
Compression successful!
```

### Decompression

```
Enter option (1 = compress, 2 = decompress): 2
Enter map file path: mp.txt
Enter binary file path to decompress: comp.bin
Enter output file path: output.txt
Decompression successful!
```

---

## Example Files

Located in the `example/` folder:

* `input.txt` – Input file
* `comp.bin` – Encoded binary
* `mp.txt` – Saved Huffman code map
* `output.txt` – Decoded output identical to `sample.txt`

---

## License

MIT License

---

## Author

P.Sai Nikhitha Reddy
