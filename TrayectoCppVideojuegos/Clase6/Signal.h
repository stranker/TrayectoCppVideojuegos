#pragma once
#include <string>
#include <iostream>
#include <stdarg.h>
#include <list>

using namespace std;

typedef void(*callback)();

class Node;

// Estructura para mantener un nodo target y su callback
struct Observer {
    Node* node;
    callback cb;
    Observer() {};
    Observer(Node* _node, callback _cb) {
        node = _node;
        cb = _cb; 
    };
};

struct Signal {
    string signalName;
    list<Observer> targets;
    void add_target(Node* node, callback cb);
    void call();
    Signal(string _name);
};