#pragma once

#include "node.h";
#include "node_factory.h"

class body : public node, public node_factory<body> {

};
