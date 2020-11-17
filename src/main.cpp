#include <iostream>
#include "all_subsets.h"

int main()
{
    std::multimap<size_t, std::vector<int>> result;
    std::set<std::vector<int>> intermediate;
    std::vector<int> original = input();
    size_t dimension = original.size();

    line();

    intermediate.insert(original);
    while(dimension > 2)
    {
        auto vect_ivect = get_vectors(intermediate);
        dimension = vect_ivect.at(0).size();
        for(auto & ivect: vect_ivect)
            split_vector(ivect, intermediate);
    }

    print(intermediate);

    result = sort_by_size(intermediate);

    line();

    print(result);

    std::cin.get();
    return 0;
}
