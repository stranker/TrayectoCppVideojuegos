#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <typeindex>
#include <typeinfo>
#include "File.h"
#include "HighscoreManager.h"

using namespace std;

template<class TipoDato> 
TipoDato myMax(TipoDato a, TipoDato b) {
	return a > b ? a : b;
}

template <typename T>
class Array {
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
    int get_size();
    bool operator>(Array<T> arr);
};

template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s]; // ej new int(5);
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

template<typename T>
int Array<T>::get_size() {
    return size;
}

template<typename T>
bool Array<T>::operator>(Array<T> arr) {
    return size > arr.get_size();
}


int main() {
	cout << myMax(3, 1) << endl;
	cout << myMax(3.0, 1.7) << endl;
	cout << myMax<double>(3.9, 1) << endl;

    int newArray[5] = { 1, 22, 3, 43, 5 };
    int newArray2[3] = { 1, 22, 3};

    Array<int> pepe(newArray, 5);
    Array<int> pepe2(newArray2, 3);

    pepe.print();
    pepe2.print();

    myMax(pepe, pepe2).print();

    cout << endl;

    int* ptrEntero;
    try {
        ptrEntero = new int(100);
    }
    catch (...) {
        cout << "Te quedaste sin memoria" << endl;
    }

    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw "No se puede dividir por cero";
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    HighscoreManager hsm(3);
    hsm.AddScore("pepe", 10);
    hsm.AddScore("pepe2", 30.99);
    hsm.AddScore("pepe3", 20);
    list<Score*> scores = hsm.GetListScores();
    list<Score*>::iterator it;

    File scoreFile;
    scoreFile.Open("scores.txt", File::WRITE);
    if (scoreFile.IsOpen()) {
        for (it = scores.begin(); it != scores.end(); it++) {
            Score* s = *it;
            scoreFile.Write(s->GetName() + "\t" + to_string(s->GetScore()) + "\n");
        }
        scoreFile.Close();
    }

	cin.get();
}