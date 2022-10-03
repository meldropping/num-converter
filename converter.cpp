#include "converter.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <exception>
#include <cmath>

using namespace std;

converter::converter() {
    status = 0;
    fromId = 0;
    toId = 0;
    fromName = "";
    toName = "";
    num = "";
    newNum = "";
}

void converter::run() {
    cout << fromPrompt;
    readFrom();
    if (getStatus() == quitId) {
        return;
    }
    cout << toPrompt;
    readTo();
    if (getStatus() == quitId) {
        return;
    }
    cout << numPrompt;
    readNum();
    if (getStatus() == quitId) {
        return;
    }
    convert();
}

void converter::convert() {
    if (getFromId() == getToId()) {
        setNewNum(getNum());
        print();
        return;
    }
    switch (getToId()) {
    case binId:
        to_bin();
        break;
    case octId:
        to_oct();
        break;
    case decId:
        to_dec();
        break;
    case hexId:
        to_hex();
        break;
    default:
        break;
    }
    print();
}

void converter::print() {
    cout << "\n" << getNum() + " " 
    << getFromName() + " = " 
    + getNewNum() + " " 
    + getToName() << endl;
}

void converter::printInstructions() {
    cout << instructions << endl;
}

void converter::readFrom() {
    string fromName;
    cin >> fromName;
    if (fromName == quitKey) {
        setStatus(quitId);
        return;
    } else if (fromName == binKey) {
        setFromId(binId);
    } else if (fromName == octKey) {
        setFromId(octId);
    } else if (fromName == decKey) {
        setFromId(decId);
    } else if (fromName == hexKey) {
        setFromId(hexId);
    } else {
        throw runtime_error(badBase);
    }
    setFromName(fromName);
}

void converter::readTo() {
    string toName;
    cin >> toName;
    if (toName == quitKey) {
        setStatus(quitId);
        return;
    } else if (toName == binKey) {
        setToId(binId);
    } else if (toName == octKey) {
        setToId(octId);
    } else if (toName == decKey) {
        setToId(decId);
    } else if (toName == hexKey) {
        setToId(hexId);
    } else {
        throw runtime_error(badBase);
    }
    setToName(toName);
}

void converter::readNum() {
    string num;
    cin >> num;
    if (num == quitKey) {
        setStatus(quitId);
        return;
    } else if (validateNum(num)) {
        setNum(num);
    }
}

// TODO: refactor if statements
bool converter::validateNum(const string &num) {
    // TODO: IMPLEMENT find_first_not_of() PERSONALLY
    switch (getFromId()) {
    case binId:
        if (num.find_first_not_of("01") != string::npos) {
            throw runtime_error(badBin);
        }
        break;
    case octId:
        if (num.find_first_not_of("01234567") != string::npos) {
            throw runtime_error(badOct);
        }
        break;
    case decId:
        if (num.find_first_not_of("0123456789") != string::npos) {
            throw runtime_error(badDec);
        }
        break;
    case hexId:
        if (num.find_first_not_of("0123456789AaBbCcDdEeFf") != string::npos) {
            throw runtime_error(badHex);
        }
        break;
    default:
        return false;
    }
    return true;
}

// ATTN: is calling getNum() within a for loop too time consuming?
// function must be called i times. is it better to access the data member directly?
void converter::to_bin() {
    int exp = 0;
    int sum = 0;
    int fromId = getFromId();
    string num = getNum();
    string newNum;
    for (int i = num.size() - 1; i >= 0; --i) {
        sum += ctoi(num[i]) * pow(fromId, exp);
        ++exp;
    }
    while (sum != 0) {
        newNum.insert(newNum.begin(), itoc(sum % binId));
        sum /= binId;
    }
    setNewNum(newNum);
}

void converter::to_oct() {
    int exp = 0;
    int sum = 0;
    int fromId = getFromId();
    string num = getNum();
    string newNum;
    for (int i = num.size() - 1; i >= 0; --i) {
        sum += ctoi(num[i]) * pow(fromId, exp);
        ++exp;
    }
    while (sum != 0) {
        newNum.insert(newNum.begin(), itoc(sum % octId));
        sum /= octId;
    }
    setNewNum(newNum);
}

void converter::to_dec() {
    int exp = 0;
    int sum = 0;
    int fromId = getFromId();
    string num = getNum();
    string newNum;
    for (int i = num.size() - 1; i >= 0; --i) {
        sum += ctoi(num[i]) * pow(fromId, exp);
        ++exp;
    }
    newNum = to_string(sum);
    setNewNum(newNum);
}

void converter::to_hex() {
    int exp = 0;
    int sum = 0;
    int fromId = getFromId();
    string num = getNum();
    string newNum;
    for (int i = num.size() - 1; i >= 0; --i) {
        sum += ctoi(num[i]) * pow(fromId, exp);
        ++exp;
    }
    while (sum != 0) {
        newNum.insert(newNum.begin(), itoc(sum % hexId));
        sum /= hexId;
    }
    setNewNum(newNum);
}

int converter::ctoi(const char &digit) {
	switch (digit) {
	case '0': case '1': case '2': 
    case '3': case '4': case '5': 
    case '6': case '7': case '8': 
    case '9':
		return digit - 48;
	case 'A': case 'B': case 'C': 
    case 'D': case 'E': case 'F':
		return digit - 55;
	case 'a': case 'b': case 'c': 
    case 'd': case 'e': case 'f':
		return digit - 87;
    default:
        return 0;
	}
}

char converter::itoc(const int &digit) {
	switch (digit) {
	case 0: case 1: case 2: 
    case 3: case 4: case 5: 
    case 6: case 7: case 8: 
    case 9:
		return digit + 48;
	case 10: case 11: case 12: 
    case 13: case 14: case 15:
		return digit + 55;
    default:
        return '0';
	}
}

void converter::setStatus(const int &status) {
    this->status = status;
}

int converter::getStatus() const {
    return this->status;
}

void converter::setFromId(const int &fromId) {
    this->fromId = fromId;
}

int converter::getFromId() const {
    return this->fromId;
}

void converter::setToId(const int &toId) {
    this->toId = toId;
}

int converter::getToId() const {
    return this->toId;
}

void converter::setFromName(const string &fromName) {
    this->fromName = fromName;
}

string converter::getFromName() const {
    return this->fromName;
}

void converter::setToName(const string &toName) {
    this->toName = toName;
}

string converter::getToName() const {
    return this->toName;
}

void converter::setNum(const string &num) {
    this->num = num;
}

string converter::getNum() const {
    return this->num;
}

void converter::setNewNum (const string &newNum) {
    this->newNum = newNum;
}

string converter::getNewNum() const {
    return this->newNum;
}