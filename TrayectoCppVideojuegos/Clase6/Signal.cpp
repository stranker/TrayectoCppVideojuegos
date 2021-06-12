#include "Signal.h"
#include "Node.h"

void Signal::add_target(Node* node, callback cb) {
	targets.push_back(Observer(node, cb));
}

// Llama a cada target que tengo con su respectivo callback
void Signal::call() {
	for (Observer observer : targets){
		observer.node->call(observer.cb);
	}
}

Signal::Signal(string _name) {
	signalName = _name;
}