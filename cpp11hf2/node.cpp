#include "node.h"

#include <iostream>
#include <stdexcept>

int node::num_of_instances = 0;
std::unordered_map<std::string, node_ptr> node::nodes_by_id;

node::node() noexcept {
	increment_instances();
}

node::node(const std::string& id) : id{ id } {
	if (id != "") {
		// itt valahogy nem másik shared_ptr-t kellene csinálni hanem az eredetit lemásolni
		nodes_by_id[id] = std::shared_ptr<node>{ this };
	}
	increment_instances();
}

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

bool node::is_everything_destructed() noexcept {
	return num_of_instances == 0;
}


node::~node() {
	if (!id.empty()) {
		nodes_by_id.erase(id);
	}
	num_of_instances--;
}

node_ptr node::find_by_id(const std::string & id) {
	if (nodes_by_id.count(id) == 0) {
		throw std::logic_error{ "There is no node with id: " + id };
	}
	return nodes_by_id[id];
}

void node::increment_instances() noexcept {
	num_of_instances++;
}

