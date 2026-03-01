#pragma once
#include <vector>
#include "my_types.h"

void measureTime(Function funcPtr, int* nums, int size, std::stringstream& ss);
void variousCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss);
void grownCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss);
void downCaseTest(Function funcPtr, const std::vector<int>& data, std::stringstream& ss);
void runTest(Function funcPtr_1, Function funcPtr_2, const std::vector<int>& data);
