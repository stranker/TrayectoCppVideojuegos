#include <iostream>
#include <string>
#include "Utils.h"

#define INCLUDE_NODES false
#define INCLUDE_POINTERS true

#if INCLUDE_NODES
#include "Node.h"

void on_visible_update_callback() {
    PRINT("on_visible_update_callback");
}

void on_player_death_callback() {
    PRINT("on_player_death");
}

#endif // INCLUDE_NODES

#if INCLUDE_POINTERS

// Creo 4 funciones con distintos parametros

void Zarlanga() {
    PRINT("Zarlanga");
}

int Suma(int num1, int num2) {
    int resultado = num1 + num2;
    return resultado;
}

int Resta(int num1, int num2) {
    int resultado = num1 - num2;
    return resultado;
}

void PrintText(const char* text) {
    PRINT(text);
}

// Creo una funcion "caller" que recibe: un puntero a funcion (func)
// que devuelve un INT y recibe 2 INTs, un entero (n1) y otro entero (n2)
void caller(int (*func)(int, int), int n1, int n2) {
    PRINT("CALLER");
    func(n1, n2);
}

// Creo una funcion "print_caller" que recibe: un puntero a funcion (func)
// que devuelve un VOID y recibe 1 const char* y un const char* (text)
void print_caller(void (*func)(const char*), const char* text) {
    PRINT("PRINT CALLER");
    func(text);
}

// Aca hago un typdef de los punteros a funcion. Permitiendome utilizar facilmente estos punteros
// tipo de retorno (* identificador)(parametros);
typedef int (*func_operacion)(int, int);
typedef void (*func_print)(const char*);
typedef void (*func_zarlanga)();

// Creo una funcion caller_operacion igual al caller anterior pero pasandole
// directamente el typedef (func_operacion) que definimos anteriormente
void caller_operacion(func_operacion fun, int n1, int n2) {
    PRINT("CALLER OPERACION");
    fun(n1, n2);
}

// Creo una funcion caller_print igual al print_caller anterior pero pasandole
// directamente el typedef (func_print) que definimos anteriormente
void caller_print(func_print fprint, const char* text) {
    PRINT("CALLER PRINT");
    fprint(text);
}

#endif // INCLUDE_POINTERS


int main() {
#if INCLUDE_NODES

    Signal on_visible_update("on_visible_update");
    Signal on_player_death("on_player_death");

    Node* node = new Node();
    Node* node2 = new Node();

    node2->add_signal(on_visible_update);
    node2->add_signal(on_player_death);

    node2->connect("on_visible_update", node, on_visible_update_callback);
    node2->connect("on_visible_update", node2, on_visible_update_callback);
    node2->connect("on_player_death", node, on_player_death_callback);

    while (node2->is_alive()){
        node2->take_damage(99);
    }

    delete node;
    delete node2;

#endif // INCLUDE_NODES

#if INCLUDE_POINTERS
    // Se pueden crear punteros a funcion con el siguiente esquema:
    // tipo de retorno (* identificador)(parametros);
    // ATENCION!! Debe coincidir el prototipo de la funcion con el prototipo del puntero a funcion
    // Por ej: int(*ptrResta)(int,int) = Zarlanga // Va a tirar error porque Zarlanga devuelve void y no recibe parametros
    void (*ptrZarlanga)() = Zarlanga;
    int (*ptrSuma)(int, int) = Suma;
    int (*ptrResta)(int, int) = Resta;
    void (*ptrPrintText)(const char*) = PrintText;

    ptrZarlanga();
    PRINT(ptrSuma(2, 2));
    PRINT(ptrResta(4, 2));
    ptrPrintText("Hola!");

    // Usando callers
    print_caller(ptrPrintText, "Chau!");
    caller(ptrSuma, 1, 1);
    caller(ptrResta, 1, 1);

    ////////////////////////////////////////////////

    // Usando punteros a funciones con el typedef
    func_operacion operacionSuma = Suma;
    func_operacion operacionResta = Resta;
    func_print printText = PrintText;
    func_zarlanga zarlanga = Zarlanga;

    zarlanga();
    PRINT(operacionSuma(22,16));
    PRINT(operacionResta(5,3));
    printText("Holay chau!");

    // Usando callers
    caller_operacion(operacionSuma, 10, 16);
    caller_operacion(operacionResta, 10, 16);
    caller_print(printText, "Buenos dias, buenas tardes y buenas noches");

#endif

    cin.get();
    return 0;
}