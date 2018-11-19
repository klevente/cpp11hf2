#include "body.h"

body::body(const std::string& id) : node{ id } {
}

const char* body::tag_name() const noexcept {
	return "body";
}
