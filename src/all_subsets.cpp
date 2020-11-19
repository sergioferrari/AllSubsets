#include "all_subsets.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>




std::vector<int> input()
{
    std::string input_str, temp;
    std::vector<int> values;
    bool valid_input = false;

    std::cout<< "insert integer values separated by comma (,) :" << std::endl;
    std::getline(std::cin, input_str);

    for(auto & c: input_str)
    {
        if(isdigit(c) || c == ',')
            valid_input = true;
    }

    if(valid_input)
    {
        std::stringstream ss(input_str);
        while(std::getline(ss, temp, ','))
        {
            values.reserve(1);
            values.push_back(std::stoi(temp));
        }
    }
    else
    {
        std::cerr << "invalid input" << std::endl;
    }

    return values;
}


void print(std::vector<int> vect)
{
    std::for_each(vect.begin(), vect.end(), [](const int i)
                  {
                      std::cout << std::setw(5) << std::right << i;
                  });
    std::cout << std::endl;
}

void print(std::set<std::vector<int>>& im)
{
    std::for_each(im.begin(), im.end(), [](const std::vector<int> vect)
                  {
                      print(vect);
                  });
    std::cout << std::endl;
}

void print(map_subsets& subs)
{
    for(auto vec = subs.rbegin(); vec != subs.rend(); ++vec)
    {
        print(vec -> second);
        std::cout << std::endl;
    }
}

void line(unsigned short n)
{
    std::cout << std::endl;
    for(unsigned short len = 0; len < n; len++ )
        std::cout << '-';
    std::cout << std::endl;
}

bool split_vector(std::vector<int> vect, std::set<std::vector<int>>& interm)
{
    size_t dim = interm.size();     // size of set container before insert
    std::vector<int> temp;
    for(size_t i = 0; i < vect.size(); ++i)
    {
        temp = vect;
        temp.erase(temp.begin()+i);
        interm.insert(temp);
        temp.clear();
    }
    return (interm.size() > dim);
}

std::vector<std::vector<int>> get_vectors(std::set<std::vector<int>>& interm)
{
    size_t minimal_size = 0;
    auto first = interm.begin();
    minimal_size = first -> size();
    std::vector<std::vector<int>> res;

    for(auto & v: interm)
    {
        minimal_size = std::min(minimal_size, v.size());
    }
    for(auto & v: interm)
    {
        if(v.size() == minimal_size)
            res.push_back(v);
    }
    return res;
}


map_subsets sort_by_size(set_subsets& sets)
{
    map_subsets mset;
    std::for_each(sets.begin(), sets.end(), [&mset](const std::vector<int>& vect)
                  {
                      mset.insert(make_pair(vect.size(), vect));
                  });
    return mset;
}
