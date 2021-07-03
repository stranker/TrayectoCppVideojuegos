#include "File.h"

void File::Open(const string& filePath, int accessMode) {
    try {
        file.open(filePath.c_str(), accessMode);
    }
    catch (ifstream::failure e) {
        cout << "Exception opening:" << e.code() << endl;
    }
}

string File::Read() {
    string output;
    string line;
    if (IsOpen()) {
        while (getline(file, line)) {
            output += line;
        }
    }
    return output;
}

char* File::ReadAsCharPointer() {
    char* data;
    int fileSize;

    file.seekg(0, ios::end);
    fileSize = file.tellg();
    file.seekg(0, ios::beg);

    data = new char[fileSize];
    file.read(data, fileSize);
    return data;
}

vector<char> File::ReadAsCharVector() {
    vector<char> innerBuffer;
    int fileSize = 0;
    file.seekg(0, ios::end);
    fileSize = file.tellg();
    file.seekg(0, ios::beg);
    innerBuffer.resize(fileSize);
    file.read((char*)&innerBuffer[0], fileSize);
    buffer = innerBuffer;
    return innerBuffer;
}

void File::Write(const string& data) {
    file << data;
}

void File::WriteLine(const string& line) {
    file.write(line.c_str(), line.size());
}

void File::Close() {
    try {
        file.close();
    }
    catch (...) {
        cout << "Exception on close file" << endl;
    }
}

bool File::IsOpen() {
    return file.is_open();
}

unsigned int File::FileSize() {
    return buffer.size();
}

File::File() {
}
