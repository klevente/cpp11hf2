#include <iostream>

#include "html.h"

int main() {
	
	{
		// <body></body>
		node_ptr root = body::create();
		// <body><p id="p1"></p></body>
		root->append_child(paragraph::create("p1"));
		node_ptr ul = unordered_list::create("my-ul");
		ul->append_child(list_item::create());
		ul->append_child(list_item::create());
		// <body><p id="p1"></p><ul id="my-ul"><li></li><li></li></ul></body>
		root->append_child(ul);
		// <body><p id="p1"></p><ul id="my-ul"><li></li><li></li></ul><p id="p2"></p></body>
		root->append_child(paragraph::create("p2"));

		root->print();
		std::cout << '\n';
		node::find_by_id("my-ul")->print();
		std::cout << '\n';
		node::find_by_id("my-ul")->append_child(list_item::create());
		node::find_by_id("my-ul")->print();
		std::cout << '\n';


		// should return <p>
		auto sibling = ul->previous_sibling();
		if (sibling) {
			sibling->print();
			std::cout << '\n';
		} else {
			std::cout << "nullptr\n";
		}
		// should return <p>
		auto sibling2 = ul->next_sibling();
		if (sibling2) {
			sibling2->print();
			std::cout << '\n';
		} else {
			std::cout << "nullptr\n";
		}
		
		// should return nullptr
		auto psibling = node::find_by_id("p1")->previous_sibling();
		if (psibling) {
			psibling->print();
			std::cout << '\n';
		} else {
			std::cout << "nullptr\n";
		}

		// should return nullptr
		auto psibling2 = node::find_by_id("p2")->next_sibling();
		if (psibling2) {
			psibling2->print();
			std::cout << '\n';
		} else {
			std::cout << "nullptr\n";
		}

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