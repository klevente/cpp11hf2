#pragma once

#include <memory>
#include <utility>

#include "node.h"

template<typename N>
struct node_factory {
	template<typename... Args>
	static node_ptr create(Args&&... args) {
		node_ptr ptr = std::make_shared<N>(std::forward<Args>(args)...);
		node::insert_node_to_set(ptr);
		node::insert_node_ptr_to_map(ptr);
		return ptr;
	}
};