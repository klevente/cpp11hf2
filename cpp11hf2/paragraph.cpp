#include "paragraph.h"

paragraph::paragraph(const std::string& id) : node{ id } {
}

const char* paragraph::tag_name() const noexcept {
	return "p";
}
