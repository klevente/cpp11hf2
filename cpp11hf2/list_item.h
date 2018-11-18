#pragma once

#include "node.h"
#include "node_factory.h"

class list_item : public node, public node_factory<list_item> {
public:


private:
	virtual const char* tag_name() const noexcept;
};
