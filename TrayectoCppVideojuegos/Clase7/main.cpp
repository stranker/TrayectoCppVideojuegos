#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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

void File::Open(const string& filePath, int accessMode) {
    file.open(filePath.c_str(), accessMode);
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
    //file.write((char*)&line[0], line.size());
}

void File::Close(){
    file.close();
}

bool File::IsOpen() {
    return file.is_open();
}

unsigned int File::FileSize() {
    return buffer.size();
}

File::File() {
}

int main() {
    ofstream output("test.txt", ios::out);
    output << "Hola, como estas?" << endl;
    output.close();

    ifstream input("test.txt");
    string data;
    if (input.is_open()){
        while (getline(input, data)){
            cout << data << endl;
        }
        input.close();
    }

    ofstream binOutput("testBin.bin", ios::binary);
    binOutput << "Chau!" << endl;
    binOutput.close();

    ifstream binInput("testBin.bin", ios::binary);
    string dataBin;
    if (binInput.is_open()){
        while (getline(binInput, dataBin)) {
            cout << dataBin << endl;
        }
        binInput.close();
    }

    fstream zarlanga("zarlanga.txt", ios::out);
    zarlanga << "Zarlanga!" << endl;
    zarlanga.close();

    File outputFile;
    outputFile.Open("zarlanga2.txt", File::WRITE);
    string asd = "Zarlanga2!";
    outputFile.WriteLine(asd);
    outputFile.Close();

    File newFile;
    vector<char> buffer;
    char* charBuffer;

    newFile.Open("zarlanga2.txt", File::READ);
    buffer = newFile.ReadAsCharVector();
    newFile.Close();

    newFile.Open("zarlanga2.txt", File::READ);
    charBuffer = newFile.ReadAsCharPointer();
    newFile.Close();

    string zarlangaOutput = string(buffer.begin(), buffer.end());
    string zarlangaChar = string(charBuffer);
    cout << "Leo los datos correctamente:" << endl;
    cout << zarlangaOutput << endl;
    cout << "Leo los datos con basura:" << endl;
    cout << zarlangaChar << endl;

    cin.get();

    return 0;
}

