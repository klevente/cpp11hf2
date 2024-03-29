#pragma once

#include "node.h"
#include "node_factory.h"

class unordered_list : public node, public node_factory<unordered_list> {
public:
	unordered_list() noexcept = default;
	unordered_list(const std::string& id);

private:

	virtual const char* tag_name() const noexcept;
};
