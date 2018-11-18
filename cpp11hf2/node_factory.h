#pragma once

#include <memory>
#include <utility>

#include "node.h"

template<typename N>
struct node_factory {
	template<typename... Args>
	static node_ptr create(Args&&... args) {
		return std::make_shared<N>(std::forward<Args>(args)...);
	}
};