#pragma once

#include "node.h"
#include "node_factory.h"

class body : public node, public node_factory<body> {
public:
	body() noexcept = default;
	body(const std::string& id);

private:
	virtual const char* tag_name() const noexcept;
};
