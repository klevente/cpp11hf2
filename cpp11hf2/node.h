#pragma once

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

class node;

using node_ptr = std::shared_ptr<node>;

class node {
public:
	
	node() noexcept;
	node(const std::string& id);
	node(const node&) = delete;
	node(node&&) = delete;

	node& operator=(const node&) = delete;
	node& operator=(node&&) = delete;

	void append_child(node_ptr child);
	
	void print() const;

	static bool is_everything_destructed() noexcept;

	virtual ~node();

	static node_ptr find_by_id(const std::string& id);
	static void insert_node_ptr_to_map(node_ptr n);

	std::string id() const;

private:
	std::vector<node_ptr> children;

	virtual const char* tag_name() const noexcept = 0;

	static int num_of_instances;

	static void increment_instances() noexcept;

	std::string id_;

	static std::unordered_map<std::string, node_ptr> nodes_by_id;
};