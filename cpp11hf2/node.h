#pragma once

#include <vector>
#include <memory>

class node;

using node_ptr = std::shared_ptr<node>;

class node {
public:
	

	






private:
	std::vector<node_ptr> children;
};