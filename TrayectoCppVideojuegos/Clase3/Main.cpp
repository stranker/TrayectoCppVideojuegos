#include <iostream>
#include "../Clase2/Archer.h"
#include <vector> // array
#include <list> // linked list
#include <map> //diccionarios
#include <queue> // colas
#include <stack> // pila
#include <algorithm> // Biblioteca que contiene funciones para trabajar las estructuras de datos anteriores

using namespace std;

int main()
{
    // Defino variables locales
    int a = 0;
    int b = 10;
    int c = 20;
    // Imprimo las direcciones de memoria
    cout << "Direccion de memoria a:" << endl;
    cout << &a << endl;  // El ampersand (&) sirve para tener la direccion de memoria de una variable
    cout << "Direccion de memoria b:" << endl;
    cout << &b << endl;
    cout << "Direccion de memoria c:" << endl;
    cout << &c << endl;
    // Las direcciones de memoria de las variables locales van bajando conforme se van creando en el programa
    // En este caso van bajando de 4 en 4 por el tamanio del entero

    // Obtener el tamanio de un tipo de dato
    cout << "El tamanio de int es:" << sizeof(int) << endl;

    // Creo una variable dinamica de tipo float
    float* ptrFloat = new float;
    // Le asigno un valor a la direccion a puntada por el puntero
    *ptrFloat = 10.0f;

    // Creo un array dinamico de tipo entero y lo lleno de valores
    int* miVector = new int[3];
    miVector[0] = 10; // En los arrays no hace falta anteponer el "*" al asignar un valor porque ya son punteros
    miVector[1] = 20;
    miVector[2] = 30;

    for (size_t i = 0; i < 3; i++) {
        cout << "El valor de mi vector en el indice:" << i << ", es:" << miVector[i] << endl;
    }

    // Usando aritmetica de punteros seria asi:
    cout << "Aritmetica de punteros:" << endl;
    int nuevoVector[3] = { 50, 100, 150 };
    int* ptrNuevoVector = nuevoVector;
    for (size_t i = 0; i < 3; i++) 		{
        cout << "El valor de mi vector en el indice:" << i << ", es:" << *(ptrNuevoVector + i) << endl;
    }

    cout << "Clases y punteros:" << endl;
    // Creo una variable dinamica archer, archer va a apuntar a una direccion de memoria que contiene un objeto del tipo Archer
    Archer* archer = new Archer(50);
    cout << "Direccion de memoria del puntero archer:" << archer << endl;
    Archer* archer2 = new Archer(100);
    cout << "Direccion de memoria del puntero archer2:" << archer2 << endl;
    Archer* archer3 = new Archer(100);
    cout << "Direccion de memoria del puntero archer3:" << archer3 << endl;
    Archer* archer4 = new Archer(100);
    cout << "Direccion de memoria del puntero archer4:" << archer4 << endl;
    // Las direcciones de memoria de las variables dinamicas van subiendo conforme se van creando en el programa
    cout << "El tamanio de la clase Player es:" << sizeof(Player) << endl;
    cout << "El tamanio de la clase Archer es:" << sizeof(Archer) << endl;

    // Creo una variable local archer.
    Archer archer5 = Archer(100);
    archer->Debug(); // En los punteros, a los metodos se los llama con "->"
    archer5.Debug(); // En las variables locales se usa el "."

    // IMPORTANTE!!!!!!
    // Siempre hacer delete de las variables dinamicas que creamos para que no haya memory leaks.
    delete archer;
    delete archer2;
    delete archer3;
    delete archer4;
    delete[] miVector;
    delete ptrFloat;
    delete ptrNuevoVector;
}