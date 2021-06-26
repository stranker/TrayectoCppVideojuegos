#pragma once

#ifdef LIBRARYAPI_DLL
#define LIBRARYAPI_DLL __declspec(dllexport) 
#else
#define LIBRARYAPI_DLL __declspec(dllimport) 
#endif