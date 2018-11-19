#pragma once

#include "node.h"
#include "node_factory.h"

class paragraph : public node, public node_factory<paragraph> {
public:
	paragraph() noexcept = default;
	paragraph(const std::string& id);

private:

	virtual const char* tag_name() const noexcept;
};
