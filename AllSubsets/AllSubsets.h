/* Copyright (C) 2021 Sergio Ferrari
*  Last update date: 2021/05/01
*  This file is provided under the MIT license
*/


#ifndef _ALLSUBSETS_H_
#define _ALLSUBSETS_H_

#include <set>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>


enum class print_option { given_set, by_value, by_size, by_reverse_size };


template<typename T>
class AllSubsets
{
public:
    AllSubsets() = default;
    virtual ~AllSubsets() = default;

    virtual bool input();
    bool set_original(std::vector<T>);
    bool reset();

    // move to private section
    std::vector<std::vector<T>> get_smaller_vectors();
    bool find_all_subsets();

    void print(print_option option = print_option::by_reverse_size, size_t wide = 5);

private:

    std::vector<T>  original;
    std::set<std::vector<T>>    all_subsets;

    bool split_vector(std::vector<T>);
    void print_single_vector(std::vector<T>, size_t wide);

};

// implementation --------------------------

template<typename T>
bool AllSubsets<T>::input()
{
    return false;
}

template<typename T>
bool AllSubsets<T>::set_original(std::vector<T> vect)
{
    if(original.empty())
        original = vect;
    if(all_subsets.empty())
        all_subsets.emplace(original);
    return all_subsets.size() == 1;
}


template<typename T>
std::vector<std::vector<T>> AllSubsets<T>::get_smaller_vectors()
{
    size_t minimal_dimension { 0 };
    std::vector<std::vector<T>> result;

    if(!all_subsets.empty())
        minimal_dimension = all_subsets.begin() -> size();

    for(auto & vect : all_subsets)
        minimal_dimension = std::min(minimal_dimension, vect.size());
    for(auto & vect : all_subsets)
    {
        if(vect.size() == minimal_dimension)
            result.push_back(vect);
    }

    return result;
}

template<typename T>
bool AllSubsets<T>::find_all_subsets()
{
    bool res { false };
    size_t dimension { 0 };
    size_t original_dimension { 0 };

    if (all_subsets.size() == 1)
    {
        dimension = all_subsets.begin() -> size();
        original_dimension = dimension;
    }

    switch(original_dimension)
    {
        case 0 :    {   std::cerr << "Error: empty set not allowed!"  << std::endl;  break; }
        case 1 :    {   res = true;     break; }
        case 2 :    {   std::vector<T> v1, v2;
                        v1.push_back(all_subsets.begin() -> at(0));
                        v2.push_back(all_subsets.begin() -> at(1));
                        all_subsets.insert(v1);
                        all_subsets.insert(v2);
                        res = true;
                        break;
                    }
        default :   {
                        while(dimension > 2)
                        {
                            auto smaller_vectors = get_smaller_vectors();
                            dimension = smaller_vectors.begin() -> size();

                            for(auto & vect: smaller_vectors)
                            {
                                split_vector(vect);
                            }
                        }
                        res = true;
                        break;
                    }
    }
    return res;
}

template<typename T>
bool AllSubsets<T>::split_vector(std::vector<T> vect)
{
    size_t dimension = all_subsets.size();     // size of set container before insert
    std::vector<T> temp;
    for(size_t i = 0; i < vect.size(); ++i)
    {
        temp = vect;
        temp.erase(temp.begin() + i);
        all_subsets.insert(temp);
        temp.clear();
    }
    return (all_subsets.size() > dimension);
}

template<typename T>
void AllSubsets<T>::print_single_vector(std::vector<T> vect, size_t wide)
{
    for(auto & el: vect)
    {
        std::cout << std::setw(wide) << std::right << el;
    }
    std::cout << std::endl;
}

template<>
void AllSubsets<std::wstring>::print_single_vector(std::vector<std::wstring> vect, size_t wide)
{
    for(auto & el: vect)
    {
        std::wcout << std::setw(wide) << std::right << el;
    }
    std::wcout << std::endl;
}

template<typename T>
void AllSubsets<T>::print(print_option option, size_t wide)
{
    switch(option)
    {
        case print_option::given_set:   {
                                            print_single_vector(original, wide);
                                            break;
                                        }
        case print_option::by_value :   {
                                            for(auto & vect: all_subsets)
                                            {
                                                print_single_vector(vect, wide);
                                            }
                                            break;
                                        }
        case print_option::by_size :    {
                                            std::multimap<size_t, std::vector<T>> map_subsets;
                                            for(auto & vect: all_subsets)
                                            {
                                                map_subsets.insert(std::make_pair( vect.size(), vect  ));
                                            }
                                            for(auto & el: map_subsets)
                                            {
                                                print_single_vector(el.second, wide);
                                            }

                                            break;
                                        }
        case print_option::by_reverse_size :    {
                                            std::multimap<size_t, std::vector<T>> map_subsets;
                                            for(auto & vect: all_subsets)
                                            {
                                                map_subsets.insert(std::make_pair( vect.size(), vect  ));
                                            }
                                            for(auto iter = map_subsets.rbegin(); iter != map_subsets.rend(); ++iter)
                                            {
                                                print_single_vector(iter->second, wide);
                                            }
                                            break;
                                        }
        default :                           break;
    }

}

template<typename T>
bool AllSubsets<T>::reset()
{
    original.clear();
    all_subsets.clear();
    return (original.empty() && all_subsets.empty());
}



#endif // header guard

