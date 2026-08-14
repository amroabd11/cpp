#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <ctime>


typedef std::vector<int> vec_seq;
typedef std::deque<int> deque_seq;
//std::vector<size_t> insertOrder;

void parse_vec(int argc, char **v, vec_seq&);


void F_Jhonson_sort(vec_seq& );
void F_Jhonson_sort_deq(deque_seq&);

double get_time();
