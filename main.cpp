#include "converter.h"
#include "constants.h"
#include <iostream>
#include <exception>

using namespace std;

int main() {
    converter obj;
    obj.printInstructions();
    while (obj.getStatus() != quitId) {
        try {
            obj.run();
        } catch (exception &err) {
            cerr << "convert error: " << err.what() << endl;
            cin.clear();
            cin.ignore(maxSize, '\n');
        }
    }
    return 0;
}