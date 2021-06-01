#include <iostream> 
#include <memory> 
#include <string> 
#include <map> 

using namespace std;

// Clase para trackear la memoria de mi programa 
class MemoryTracker {
public:
    static unsigned int totalMemoryAllocated; // Memoria total alocada 
    static unsigned int totalMemoryFreed; // Memoria total liberada 
    static unsigned int CurrentMemoryUsage() { return totalMemoryAllocated - totalMemoryFreed; }; // Memoria actualmente usada 
    static void PrintCurrentMemory() { cout << "Current memory usage " << CurrentMemoryUsage() << " bytes" << endl; }; // Imprimo memoria actual 
};

unsigned int MemoryTracker::totalMemoryAllocated = 0; // Inicializo las variables estaticas 
unsigned int MemoryTracker::totalMemoryFreed = 0;

// Sobreescribo el metodo "new" 
void* operator new(size_t size) {
    cout << "Allocating " << size << " bytes" << endl;
    MemoryTracker::totalMemoryAllocated += size; // int 4bytes; char 1byte 
    return malloc(size);
}

// Sobreescribo el metodo "delete" 
void operator delete(void* pointer, size_t size) {
    cout << "Freeing " << size << " bytes" << endl;
    MemoryTracker::totalMemoryFreed += size;
    free(pointer);
}

// Estructura de un Vector2 
struct Vector2 {
    int x = 0;
    int y = 0;
    Vector2 operator+(const Vector2& vector) { // Declaro que hace la funcion "+" para mi Vector2 
        return Vector2(x + vector.x, y + vector.y);
    };
    Vector2 operator-(const Vector2& vector) {// Declaro que hace la funcion "-" para mi Vector2 
        return Vector2(x - vector.x, y - vector.y);
    };
    Vector2() {};
    Vector2(int _x, int _y) { x = _x; y = _y; };
    void Print() { cout << "Vector2(" << x << "," << y << ")" << endl; };
};

// Estructura de un Vector3 
struct Vector3 {
    int x = 0;
    int y = 0;
    int z = 0;
    Vector3() {};
    Vector3(int _x, int _y, int _z) { x = _x; y = _y; z = _z; };
    void Print() { cout << "Vector3(" << x << "," << y << "," << z << ")" << endl; };
};

int main() {
    // Creo 3 vectores2 
    Vector2 velocity = Vector2(0, 100);
    Vector2 pos = Vector2(0, -50);
    Vector2 result = velocity + pos;
    //Imprimo sus datos 
    velocity.Print();
    pos.Print();
    result.Print();
    // Imprimo sus direcciones de memoria 
    cout << "Direccion de memoria de velocity:" << &velocity << endl;
    cout << "Direccion de memoria de pos:" << &pos << endl;
    cout << "Direccion de memoria de result:" << &result << endl;

    // Imprimo la memoria actual alocada 
    MemoryTracker::PrintCurrentMemory();
    // Creo variables dinamicas del tipo Vectores2  
    Vector2* motion;
    motion = new Vector2(2, 2);
    MemoryTracker::PrintCurrentMemory();
    Vector2* zarlaga = new Vector2(5, 5);
    MemoryTracker::PrintCurrentMemory();
    Vector2* zarlaga2 = new Vector2(5, 10);
    MemoryTracker::PrintCurrentMemory();

    // Hago un delete de las variables 
    delete zarlaga;
    delete zarlaga2;
    delete motion;
    MemoryTracker::PrintCurrentMemory();

    // NOTA: Al crear un string internamente hace un "new". Por eso vemos cuando se aloca la memoria de este string y cuando se libera 
    // al finalizar el scope de la variable. En este caso no hace falta hacer un delete de un string 
    {
        string nombre = "Josesito";
        MemoryTracker::PrintCurrentMemory();
    }
    MemoryTracker::PrintCurrentMemory();
    cin.get();
}
