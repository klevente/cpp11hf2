#include "unordered_list.h"

unordered_list::unordered_list(const std::string& id) : node{ id } {
}

const char* unordered_list::tag_name() const noexcept {
	return "ul";
}
