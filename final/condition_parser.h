#pragma once

#include "node.h"

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
