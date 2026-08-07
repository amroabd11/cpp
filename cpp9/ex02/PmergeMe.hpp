#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>


typedef std::vector<int> vec_seq;
//std::vector<size_t> insertOrder;

void parse_vec(int argc, char **v, vec_seq&);


void F_Jhonson_sort(vec_seq&);
