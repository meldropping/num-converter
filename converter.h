#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>

using namespace std;

class converter {
    public:
        converter();

        void run();
        void convert();
        void print();
        void printInstructions();

		void readFrom();
		void readTo();
		void readNum();

        bool validateNum(const string &num);

        void to_bin();
        void to_oct();
        void to_dec();
        void to_hex();

        int ctoi(const char &digit);
        char itoc(const int &digit);

        void setStatus(const int &status);
        int getStatus() const;
        void setFromId(const int &fromId);
        int getFromId() const;
        void setToId(const int &toId);
        int getToId() const;
        void setFromName(const string &fromName);
        string getFromName() const;
        void setToName(const string &toName);
        string getToName() const;
        void setNum(const string &num);
        string getNum() const;
        void setNewNum(const string &newNum);
        string getNewNum() const;

    private:
        int status;
        int fromId;
        int toId;
        string fromName;
        string toName;
        string num;
        string newNum;
};

#endif