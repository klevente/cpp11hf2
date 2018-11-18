#pragma once

#include "node.h"
#include "node_factory.h"

class paragraph : public node, public node_factory<paragraph> {

};
