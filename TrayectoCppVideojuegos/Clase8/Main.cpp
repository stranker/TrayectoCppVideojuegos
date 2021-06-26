#include <iostream>
#include <Windows.h>
#include <string>

// Defino 2 punteros a funcion
typedef float(*operacion)(float, float);
typedef std::string(* zarlanga)();

int main(){
    // Copio el path donde tengo guardada mi DLL
    //LPCWSTR path = L"C:\\Users\\Daniel\\Documents\\Proyectos\\C++\\TrayectoCppVideojuegos\\TrayectoCppVideojuegos\\x64\\Debug\\Clase8DLL.dll";
    LPCWSTR path = L"Clase8DLL.dll"; // En este caso como mi directorio de salida de la DLL es el mismo que el de mi .exe de Clase8
                                     // Voy a poder directamente cargar al path con el nombre de mi DLL
    HINSTANCE clase8DLL = LoadLibrary(path);

    if (!clase8DLL) {
        std::cout << "could not load the dynamic library" << std::endl;
        return EXIT_FAILURE;
    }

    // Obtengo las funciones/metodos de mi DLL y los guardo en punteros a funcion
    // [puntero a funcion] [nombre variable] = [Casteo a puntero a funcion]GetProcAddress([Mi DLL], [Nombre funcion])
    operacion suma = (operacion)GetProcAddress(clase8DLL, "Suma");
    operacion resta = (operacion)GetProcAddress(clase8DLL, "Resta");
    zarlanga zarlangaFunc = (zarlanga)GetProcAddress(clase8DLL, "Zarlanga");

    if (!suma) {
        std::cout << "could not locate the function Suma" << std::endl;
        return EXIT_FAILURE;
    }
    if (!resta) {
        std::cout << "could not locate the function Resta" << std::endl;
        return EXIT_FAILURE;
    }
    if (!zarlangaFunc) {
        std::cout << "could not locate the function Zarlanga" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "suma() returned " << suma(5, 5) << std::endl;
    std::cout << "resta() returned " << resta(1, 5) << std::endl;
    std::cout << "Zarlanga() returned " << zarlangaFunc() << std::endl;

    std::cin.get();

    return EXIT_SUCCESS;
}

/*
IMPORTAR DLL EN UNITY

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System.IO;
using System;

public class TestDLL : MonoBehaviour
{
    [DllImport("Clase8DLL", EntryPoint="Suma")]
    public static extern float Suma(float a, float b);
    [DllImport("Clase8DLL")]
    public static extern float Resta(float a, float b);
    void Start()
    {
        Debug.Log("Test:Start");
        float ret = Suma(3, 7);
        float ret2 = Resta(1, 7);
        Debug.Log(ret);
        Debug.Log(ret2);
    }
}
*/