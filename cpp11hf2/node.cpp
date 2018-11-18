#include "node.h"

#include <iostream>

void node::append_child(node_ptr child) {
	children.push_back(child);
}

void node::print() const {
	std::cout << '<' << tag_name() << '>';

	for (const auto& c : children) {
		c->print();
	}

	std::cout << '<' << '/' << tag_name() << '>';
}
