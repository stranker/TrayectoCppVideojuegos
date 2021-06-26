#pragma once
#include "Export.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

extern "C" {
	LIBRARYAPI_DLL float Suma(float a, float b);
	LIBRARYAPI_DLL float Resta(float a, float b);
	LIBRARYAPI_DLL float Multiplicacion(float a, float b);
	LIBRARYAPI_DLL float Division(float a, float b);
	LIBRARYAPI_DLL string Zarlanga();
	int Test();
}
