#include <iostream>
#include "AllSubsets.h"

using namespace std;

int main()
{

    std::vector<int> orig_int;
    std::vector<int> orig_int1 { 1 };
    std::vector<int> orig_int2 { 1, 2 };
    std::vector<int> orig_int3 { 1, 2, 2, 3, 8 };

    std::vector<std::string> instruments{ "violin", "violin", "viola", "cello", "clarinet" };
    std::vector<std::wstring> colors{ L"red", L"blue", L"yellow", L"green" };

    
    AllSubsets<int> asint;
    asint.set_original(orig_int);
    std::cout << "Passing an empty vector to AllSubsets, you get the following error:" << std::endl;
    asint.find_all_subsets();
    asint.print(print_option::by_reverse_size, 5);
    asint.reset();

    std::cout << std::endl;

    AllSubsets<int> asint1;
    asint1.set_original(orig_int1);
    std::cout << "Passing a given one-item set to AllSubsets, you get the following output: " << std::endl;
    asint1.find_all_subsets();
    asint1.print(print_option::by_reverse_size, 5);
    asint1.reset();

    std::cout << std::endl;

    AllSubsets<int> asint2;
    asint2.set_original(orig_int2);
    std::cout << "Passing a given two-item set to AllSubsets, you get the following output: " << std::endl;
    asint2.find_all_subsets();
    asint2.print(print_option::by_reverse_size, 5);
    asint2.reset();

    std::cout << std::endl;

    AllSubsets<int> asint3;
    asint3.set_original(orig_int3);
    std::cout << "Passing a given set with more than two elements to AllSubsets, you get the following output: " << std::endl;

    asint3.find_all_subsets();
    asint3.print(print_option::by_reverse_size, 5);
    asint3.reset();

    std::cout << std::endl;

    AllSubsets<std::string> asstrings;
    asstrings.set_original(instruments);
    std::cout << "with the following musical instruments:" << std::endl;
    asstrings.print(print_option::given_set, 10);
    std::cout << "you can form the following organics:" << std::endl;
    asstrings.find_all_subsets();
    asstrings.print(print_option::by_reverse_size, 10);
    asstrings.reset();

    std::cout << std::endl;

    AllSubsets<std::wstring> aswstrings;
    aswstrings.set_original(colors);
    std::cout << "You can print the output by value (in this case alpabetical):" << std::endl;
    aswstrings.find_all_subsets();
    aswstrings.print(print_option::by_value, 10);
    aswstrings.reset();



    return 0;
}
