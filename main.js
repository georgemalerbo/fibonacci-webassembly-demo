/* ---------------------------------------- main.js ----------------------------------------
 * - Works with "fibonacci.cpp" compiled to WebAssembly
 * - This file will handle user interaction to obtain the value of "n", and the one WebAssembly function call
 * ---------------------------------------------------------------------------------- */

// Get the DOM elements on the HTML page to display log messages to the user
// The "terminal" (outer container) and "terminalContent" (text content) variables refer to a "terminal" HTML DOM element to be displayed in the center of the page
// that will be used to display log messages to the user
let terminal = document.getElementById("terminal"); // The outer container for the terminal HTML DOM element
let terminalContent = document.getElementById("terminal-content"); // The text content of the terminal HTML DOM element

// Store the JavaScript console.log function in a variable "originalConsoleLog"
const originalConsoleLog = console.log;

/* ---------------------- Custom console.log function ------------------------------
 * - My goal is to "mirror" the browser console to a fake terminal DOM element in the web page
 * - Outputs messages to the "terminal" DOM element in center of web page
 * - Appends new log entries to the "terminal" HTML DOM element in center of web page
 * - Maintains original console.log functionality in the real browser console
 * --------------------------------------------------------------------------------- */
console.log = function (text) {
  // In this function, maintain original console.log behavior
  originalConsoleLog.apply(console, arguments);

  // Add line to terminal DOM element display and use <br>
  terminalContent.innerHTML += text + "<br>";
};

/* ---------------------- Enable Run button ----------------------------------------
 * - WebAssembly module needs to be loaded and ready before it can be called from JavaScript
 * --------------------------------------------------------------------------------- */

// When the WebAssembly module is initialized, enable the "Run" button
Module.onRuntimeInitialized = function () {
  // Get the "runButton" DOM element by its ID
  const runButton = document.getElementById("runButton");
  // By default, the "disabled" attribute is set to true, which prevents the button from being clicked
  // Set the "disabled" attribute to false, which enables the button
  runButton.disabled = false;
};

/* ---------------------- Event listener for Run button ------------------------------
 * - Prompt to input a value for n
 * - Calls the C++ "fibonacci" function
 * - Displays result of Fibonacci function call to user via the terminal emulator
 * ---------------------------------------------------------------------------------- */
// Attach an event listener "click" to the "Run" button
document.getElementById("runButton").addEventListener("click", () => {
  // Prompt the user to enter a value for "n"
  const n = parseInt(prompt("Enter the value of n:"));

  /* ---------------------- Call the C++ "fibonacci" function with the user-supplied value "n" using Emscripten"s "ccall" function ----------------------
   * The "ccall" function takes arguments and converts the arguments to the correct data type in a way that is understood by WebAssembly
   * Then the function executes the C++ function in WebAssembly, then returns the result in a format that can be understood by JavaScript.
   */

  const result = Module.ccall(
    "fibonacci", // The name of the C++ function to call
    "number", // The return type of the function
    ["number"], // An array of argument types, in this program there is only a single argument of type
    [n] // An array of argument values, containing the user-supplied value of "n". No other values
  );

  /* ---------------------- Display the result of the Fibonacci function ----------------------
   * - Output the result of the function call to the user via the terminal emulator
   * ------------------------------------------------------------------------------------------- */
  console.log(
    `The Fibonacci number at position ${n} in the sequence is: ${result}`
  );
});
