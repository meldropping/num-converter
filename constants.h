#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// IDS
const int binId = 2;
const int octId = 8;
const int decId = 10;
const int hexId = 16;
const int quitId = -1;

// INPUT KEYS
const string binKey = "bin";
const string octKey = "oct";
const string decKey = "dec";
const string hexKey = "hex";
const string quitKey = "q";

// ERROR MSGS
const string badBase = "invalid base";
const string badBin = "invalid binary number";
const string badOct = "invalid octal number";
const string badDec = "invalid decimal number";
const string badHex = "invalid hexadecimal number";

// PROMPTS
const string fromPrompt = "\nEnter a base to convert from: ";
const string toPrompt = "Enter a base to convert to: ";
const string numPrompt = "Enter a number: ";

// INSTRUCTIONS
const string instructions = "\nConvert from one number system to another."
                            "\nPossible inputs for a base to be converted"
                            "\nfrom or to are \"bin\", \"oct\", \"dec\", or"
                            "\n\"hex\"; all of which represent the number"
                            "\nsystems of the same name. The input number must"
                            "\ncorrespond to the base you are converting from."
                            "\nEnter the character 'q' at any time to"
                            "\nterminate the program.";

// MAX BUFFER SIZE
const long int maxSize = numeric_limits<streamsize>::max();

#endif