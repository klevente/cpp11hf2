#pragma once

#include "node.h"
#include "node_factory.h"

class unordered_list : public node, public node_factory<unordered_list> {

};