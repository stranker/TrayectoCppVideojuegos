#include "Node.h"


bool Node::is_alive() const {
	 return health > 0;
}

void Node::take_damage(int value) {
    health -= value;
    if (health <= 0) {
        emit_signal("on_player_death");// Emito la senial on_player_death a todos los nodos que la escuchan
        set_visible(false);
    }
}

void Node::set_visible(bool value) {
    is_visible = value;
    emit_signal("on_visible_update"); // Emito la senial on_visible_update a todos los nodos que la escuchan
}

void Node::call(callback cb) {
    cb();
}

void Node::connect(string _signalName, Node* target, callback cb) {
    // Si tengo la senial, le conecto un target y su callback
    for (size_t i = 0; i < signals.size(); i++){
        if (signals[i].signalName == _signalName) {
            signals[i].add_target(target, cb);
        }
    }
}

void Node::add_signal(Signal signal) {
    signals.push_back(signal);
}

void Node::emit_signal(string signalName) {
    for (Signal signal : signals){
        if (signal.signalName == signalName){
            signal.call(); // Si tengo a esa senial, la llamo
        }
    }
}
