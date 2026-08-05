#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>


std::vector<int> vec_seq;
std::vector<int> jacob_numbers;

void parse_vec(int argc, char **v, vec_seq&);


void F_Jhonson_sort(vec_seq&, long);
