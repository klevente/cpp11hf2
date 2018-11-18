#pragma once

#include <vector>
#include <memory>

class node;

using node_ptr = std::shared_ptr<node>;

class node {
public:
	
	void append_child(node_ptr child);
	
	void print() const;





private:
	std::vector<node_ptr> children;

	virtual const char* tag_name() const noexcept = 0;
};