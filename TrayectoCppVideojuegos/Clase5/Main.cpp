#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

int suma(int* valor1, int* valor2) {
    return *valor1 + *valor2;
}

void intercambio(int* valor1, int* valor2) {
    int temp = *valor1;
    *valor1 = *valor2;
    *valor2 = temp;
}

void intercambio2(int& valor1, int& valor2) {
    int temp = valor1;
    valor1 = valor2;
    valor2 = temp;
}

void zarlanga(int& valor) {
    valor = 100;
}


class Transform {

};

class Component {
public:
    Component() {};
    ~Component() { cout << "Component destructor" << endl; };
    void ToString() { cout << "Soy un component" << endl; };
    void Update(float deltaTime) {};
};

class Object {
private:
    string name;
    vector<shared_ptr<Component>> components;
public:
    void AddComponent(shared_ptr<Component> component) { components.push_back(component); };
    Object(string _name) { 
        name = _name;
        cout << "Object constructor name:" << name << endl;
    };
    void Update(float deltaTime);
    ~Object() { cout << "Object destructor name:" << name << endl; };
    void ComponentsSize() { cout << "Components size:" << components.size() << endl; };
};


int main()
{
    int x = 1;
    int y = 2;

    cout << "Suma x e y:" << suma(&x, &y) << endl;
    cout << endl;

    cout << "Intercambio x e y con funcion intercambio:" << endl;
    intercambio(&x, &y);

    cout << x << endl;
    cout << y << endl;
    cout << endl;

    cout << "Intercambio de nuevo x e y con funcion intercambio2:" << endl;
    intercambio2(x, y);

    cout << x << endl;
    cout << y << endl;
    cout << endl;

    cout << "Asigno a speed por referencia con funcion zarlanga:" << endl;
    int speed;
    zarlanga(speed);
    cout << "Speed:" << speed << endl;
    cout << endl;

    // SMART POINTERS VS RAW POINTERS

    // Raw pointer
    cout << "Raw pointer:" << endl;
    {
        Object* rawObject = new Object("rawObject"); // Creo el objecto con raw pointer
        rawObject->ComponentsSize(); // Imprimo size de components = 0
    }

    // Nunca se borra en memoria el objeto apuntado por rawObject. Por ende, no se llama a su destructor. MEMORY LEAK!
    cout << endl;

    cout << "Smart pointer:" << endl;
    // Smart pointers
    {
        unique_ptr<Object> smartObject(new Object("smartObject")); // Creo el objecto smartObject con un unique_ptr
        smartObject->ComponentsSize();
        // unique_ptr: Este puntero SOLO puede tener UN owner. Por ende, no se pueden utilizar en vectores, listas, etc.
    }
    // Se elimina el puntero y se llama al destructor de Object
    cout << endl;

    Object* obj2 = new Object("obj2");
    cout << "Raw pointer y Smart pointer:" << endl;
    {
        Object* obj1 = new Object("obj1");

        shared_ptr<Component> c1(new Component());
        shared_ptr<Component> c2(new Component());
        shared_ptr<Component> c3(new Component());
        // shared_ptr: Este puntero puede tener multiple owners. Se va a eliminar una vez que se eliminen todos los owner/referencias.

        obj1->AddComponent(c1);
        obj1->AddComponent(c2);
        obj1->AddComponent(c3);

        obj1->ComponentsSize();
        delete obj1;
    }

    obj2->ComponentsSize();

    delete obj2;

    cin.get();
}

void Object::Update(float deltaTime) {
    for (size_t i = 0; i < components.size(); i++){
        components[i]->Update(deltaTime);
    }
    //render();
    //Update();
}
