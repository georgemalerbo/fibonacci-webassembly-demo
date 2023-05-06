# Fibonacci WebAssembly Demo

This is a simple web app that demonstrates using WebAssembly with C++. Created to experiment with WebAssembly, and understand how it can be used in web apps. The project was a valuable learning experience not only in web development, but also in C++ in learning how to implement the Fibonacci algorithm.

## Table of Contents

- [Files](#files)
- [Getting Started](#getting-started)
- [Compiling C++ to WebAssembly](#compiling-c-to-webassembly)
- [Usage](#usage)

## Files

- **fibonacci.cpp**: This file contains the C++ implementation of the Fibonacci function, which will be compiled to WebAssembly.
- **index.html**: This file contains the HTML structure and references to the necessary JavaScript and CSS files for the web app.
- **main.js**: This file contains the JavaScript code that handles user interaction and WebAssembly function calls.
- **styles.css**: This file contains the local CSS styles for the web app.

## Getting Started

### Option 1: Download Files

- Clone the repository or download the source files.

- To run the web app, you need to compile the C++ code to WebAssembly using the Emscripten compiler. You can follow the instructions on their [official website](https://emscripten.org/docs/getting_started/downloads.html) to download and install the Emscripten SDK.

### Option 2: View Hosted Page

- Alternatively, you can view the webpage as it is hosted on GitHub pages with this link: https://georgemalerbo.github.io/fibonacci-webassembly-demo/

### Compiling C++ to WebAssembly

- The `fibonacci.cpp` file can be compiled to WebAssembly using the Emscripten compiler.

- After installing Emscripten, run the following command to compile `fibonacci.cpp` to WebAssembly:

`emcc -s WASM_BIGINT=1 -s EXPORTED_FUNCTIONS="["_fibonacci"]" -s "EXPORTED_RUNTIME_METHODS=["ccall"]" fibonacci.cpp -o fibonacci_wasm.js`

- After running the Emscripten command, two files should be generated: `fibonacci_wasm.js` and `fibonacci_wasm.wasm`

- These files are necessary to run the web app and to call the WebAssembly function from JavaScript.

## Usage

1. Open `index.html` by launching a local web server like Visual Studio Code Live Server extension
2. Click the "Run" button.
3. Enter a value for `n` when prompted.
4. The web app will display the Fibonacci number at the nth position.
