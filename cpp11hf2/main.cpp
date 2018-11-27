#include <iostream>

#include "html.h"

int main() {
	
	{
		node_ptr root = body::create();
		root->append_child(paragraph::create());
		node_ptr ul = unordered_list::create("my-ul");
		ul->append_child(list_item::create());
		ul->append_child(list_item::create());
		root->append_child(ul);
		root->append_child(paragraph::create());

		root->print();
		std::cout << '\n';
		node::find_by_id("my-ul")->print();
		std::cout << '\n';

		auto s = ul->previous_sibling();
		s->print();

	}

	try {
		node::find_by_id("my-ul")->print();
	}
	catch (std::exception& e) {
		std::cout << e.what() << '\n';
	}

	std::cout << node::is_everything_destructed() << '\n';

	system("pause");
	return 0;
}