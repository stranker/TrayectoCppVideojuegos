#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class File {
private:
    fstream file;
    vector<char> buffer;
public:
    enum AccessMode {
        READ = 1,
        WRITE = 2,
        READ_WRITE = 7
    };
    void Open(const string& filePath, int accessMode);
    string Read();
    char* ReadAsCharPointer();
    vector<char> ReadAsCharVector();
    void Write(const string& data);
    void WriteLine(const string& line);
    void Close();
    bool IsOpen();
    unsigned int FileSize();
    File();
};