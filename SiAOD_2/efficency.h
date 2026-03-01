#pragma once
#include <vector>
#include "my_types.h"

void measureTime(Function funcPtr, char* chr, int n, char key);
void worstCaseTest(Function funcPtr, const std::vector<int>& data);
void mediumCaseBothTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data);
void bestCaseTest(Function funcPtr_1, const std::vector<int>& data);
void runTest(Function funcPtr_1, Function functPtr_2, const std::vector<int>& data);