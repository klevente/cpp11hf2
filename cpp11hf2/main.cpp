#include <iostream>

#include "html.h"

int main() {
	node_ptr root = body::create();
	root->append_child(paragraph::create());
	node_ptr ul = unordered_list::create();
	ul->append_child(list_item::create());
	ul->append_child(list_item::create());
	root->append_child(ul);
	root->append_child(paragraph::create());

	root->print();

	system("pause");
	return 0;
}