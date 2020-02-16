#include "test_traversal.hpp"
#include "BinarySearch.hpp"
#include "SieveOfEratosthenes.hpp"

#include <iostream>

extern void try_traversal();
extern ll binary_search(ll left, ll right, std::vector<ll> a, ll key);


void sample_traversal()
{
    try_traversal();
}


void sample_binary_search()
{
    std::vector<ll> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

    std::cout << binary_search(-1, a.size(), a, 51) + 1 << std::endl;
    std::cout << binary_search(-1, a.size(), a, 1) + 1 << std::endl;
    std::cout << binary_search(-1, a.size(), a, 10) + 1 << std::endl;
    std::cout << binary_search(-1, a.size(), a, 780) + 1 << std::endl;
    std::cout << binary_search(-1, a.size(), a, 7800) + 1 << std::endl;
}

void sample_sieve()
{
    SieveOfEratosthenes s = SieveOfEratosthenes(100);

    s.print_table();
    for (auto const& e: s.factor(2)) {
        std::cout << e.first << ", " << e.second << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    // sample_traversal();
    // sample_binary_search();
    sample_sieve();

    return 0;
}
