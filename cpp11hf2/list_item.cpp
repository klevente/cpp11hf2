#include "list_item.h"

list_item::list_item(const std::string& id) : node{ id } {
}

const char* list_item::tag_name() const noexcept {
	return "li";
}
