#ifndef _ALL_SUBSETS_H_
#define _ALL_SUBSETS_H_

#include <map>
#include <set>
#include <vector>


using map_subsets = std::multimap<size_t, std::vector<int>>;
using set_subsets = std::set<std::vector<int>>;


// functions -----------------------------------------------
std::vector<int> input();

void print(std::vector<int> vect);

void print(set_subsets& subs);

void print(map_subsets& subs);

void line(unsigned short n = 50);

// If the input vector(vec) has the size N, N vectors of size N-1 will be created.
bool split_vector(std::vector<int>, std::set<std::vector<int>>&);

std::vector<std::vector<int>> get_vectors(std::set<std::vector<int>>& );

map_subsets sort_by_size(set_subsets& sets);

#endif // header guard

