// Compiling C++ to WebAssembly using Emscripten command:
// --------------------------------------------------------------------------------------------------------------------------------------------------- //
//
// " emcc -s WASM_BIGINT=1 -s EXPORTED_FUNCTIONS="["_fibonacci"]" -s "EXPORTED_RUNTIME_METHODS=["ccall"]" fibonacci.cpp -o fibonacci_wasm.js "
//
//   emcc: Emscripten command that compiles C/C++ code to WebAssembly
//   -s WASM_BIGINT=1: Sets the Emscripten setting WASM_BIGINT to 1, support for 64-bit integers
//   -s EXPORTED_FUNCTIONS="["_fibonacci"]": Exports the "fibonacci" function from the compiled WebAssembly
//   -s "EXPORTED_RUNTIME_METHODS=["ccall"]": Exports the "ccall" method for the compiled WebAssembly module
//   fibonacci.cpp: The input C++ file to be compiled which contains the single C++ function
//   -o fibonacci_wasm.js: The automatically generated JavaScript "glue" file which will contain reference to the .wasm binary file "wasmBinaryFile = 'fibonacci_wasm.wasm';""
// --------------------------------------------------------------------------------------------------------------------------------------------------- //

// ------------------- Header Files -------------- 
// Include C++ headers
// ----------------------------------------------- //
#include <iostream>
#include <vector>

// ------------------- Extern C Wrapper -----------------
// The function has to be inside "extern "C" to enable calling the function from JavaScript
// the function should use "C linkage"
// ---------------------------------------- //
extern "C" {
// ---------------------------------------- //

    // ------------------- Function Declaration -----------------
    // This declares a function named "fibonacci". Takes an integer "num", and returns a value of type "long long"
    // ---------------------------------------------------------------------------- //
    long long fibonacci(int num) {
        // Function declaration:
        // - declares a function named "fibonacci" that takes an integer "num" as input
        // - returns a value of type "long long"
        // - "long long" type is a larger integer type than "int"
        // ---------------------------------------------------------------------------- //

        // ------------------- Base Case -----------------
        // Handles the Fibonacci sequence "base case"
        // - If "num" is 0 or 1, return "num" as the result.
        // ------------------------------------------------ //
        if (num <= 1) {
            return num;
        }
        // ------------------------------------------------ //

        // ------------------- Create Vector -----------------
        // Creates a vector to store the values of the Fibonacci sequence
        // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
        std::vector<long long> fibSequence(num + 1); // Create a vector to store the values of the Fibonacci sequence:
        fibSequence[0] = 0;
        fibSequence[1] = 1;
        // - Vectors are "dynamic" arrays
        //     - Here the vector is used to store the Fibonacci numbers in sequence as they are calculated in the loop
        // - We create a new vector called "fibSequence" using the vector class template with the "<long long>" syntax specifying the data type.
        //     - The size of the vector is specified using parentheses "()"
        //         - The size is set to "num + 1".
        //         - This creates a vector with "num+1" elements
        //         - The first element is at index 0 and the last element is at index "num".
        // - After the vector is created, we can access and change the elements using square bracket "[]" syntax.
        //     - Here the size of the vector is fixed at the initial size (num+1)
        //         - Size of vector does not change during loop
        // --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

        // ------------------- Loop -----------------
        // Calculates Fibonacci sequence values and stores them in the "fibSequence" vector
        // --------------------------------------------------------------------------------------------------------------------------- //
        for (int i = 2; i <= num; i++) { // Loop will iterate over each number in the sequence up to "num".
            //     - The value of "i" starts at 2:
            //     - the first two values in the sequence are predefined as 0 and 1.

            fibSequence[i] = fibSequence[i - 1] + // - The value at index "i-1" is the previous value in the sequence.
                            fibSequence[i - 2];    // - The value at index "i-2" is the value before that.
                                                    // - Adding these two values together gives the next value in the sequence.

            // After each iteration of the loop :
            //     - The value is stored in the "fibSequence" vector at index "i".
        } // When the loop is finished, the vector contains all values in the sequence
          //     - with the value of "num" at the end
        // --------------------------------------------------------------------------------------------------------------------------- //

        // ------------------- Return Result -----------------
        // Returns the final value of sequence
        // ------------------------------------------------------------ //
        return fibSequence[num]; // Return the final value of the sequence:
                                 // - vector "fibSequence" at this point now contains Fibonacci numbers up to "num".
                                 // - Return the value at index "num" for the result.
                                 //     - The value can now be used in JavaScript
        // ------------------------------------------------------------ //
    }
}

