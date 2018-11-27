#include "node.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>

int node::num_of_instances = 0;
std::unordered_map<std::string, node_w_ptr> node::nodes_by_id;
std::list<node_w_ptr> node::all_nodes;

node::node() noexcept {
	increment_instances();
}

node::node(const std::string& id) : id_{ id } {
	increment_instances();
}

void node::append_child(node_ptr child) {
	node_w_ptr parent_ptr = *std::find_if(all_nodes.begin(), all_nodes.end(), [this](const auto& p) {
		return p.lock().get() == this;
	});
	child->set_parent_node(parent_ptr);
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
	if (!id_.empty()) {
		nodes_by_id.erase(id_);
	}
	num_of_instances--;
}

node_ptr node::find_by_id(const std::string & id) {
	if (nodes_by_id.count(id) == 0) {
		throw std::logic_error{ "There is no node with id: " + id };
	}
	return nodes_by_id[id].lock();
}

void node::insert_node_ptr_to_map(const node_ptr n) {
	if (!n->id_.empty()) {
		nodes_by_id[n->id_] = node_w_ptr{ n };
	}
}

void node::insert_node_to_set(const node_ptr n) {
	all_nodes.push_back(node_w_ptr{ n });
}

std::string node::id() const {
	return id_;
}

node_ptr node::parent_node() const {
	return parent_node_.lock();
}

node_ptr node::previous_sibling() const {
	node_ptr parent;
	if (parent = parent_node()) {
		auto pos = std::find_if(parent->children.begin(), parent->children.end(), [this](const auto& p) {
			return p.get() == this;
		});
		if (pos == parent->children.begin()) {
			return nullptr;
		}
		return *(pos-1);
	}
	else {
		throw std::logic_error{ "cannot find parent!" };
	}
}

node_ptr node::next_sibling() const {
	node_ptr parent;
	if (parent = parent_node()) {
		auto pos = std::find_if(parent->children.begin(), parent->children.end(), [this](const auto& p) {
			return p.get() == this;
		});
		if (pos == parent->children.end()) {
			return nullptr;
		}
		return *(pos + 1);
	}
	else {
		throw std::logic_error{ "cannot find parent!" };
	}
}

void node::increment_instances() noexcept {
	num_of_instances++;
}

void node::set_parent_node(const node_w_ptr parent) {
	parent_node_ = node_w_ptr{ parent };
}

