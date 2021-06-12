#pragma once

#include <vector>
#include <string>
#include "Signal.h"

class Node {
private:
    vector<Signal> signals;
    bool is_visible = false;
    int health = 100;
public:
    Node() {};
    ~Node() {};
    bool is_alive() const;
    void take_damage(int value);
    void set_visible(bool value);
    void call(callback cb);
    void connect(string signal, Node* target, callback cb);
    void add_signal(Signal signal);
    void emit_signal(string signalName);
};
