#ifndef __SIEVE_OF_ERATOSTHENES_HPP__
#define __SIEVE_OF_ERATOSTHENES_HPP__

#include <vector>

using Pair = std::pair<int, int>;

class SieveOfEratosthenes
{
    int n;
    std::vector<int> table;
    std::vector<int> primes;

    std::vector<int> factors(std::size_t x);

public:
    SieveOfEratosthenes(const std::size_t n);
    bool is_prime(const std::size_t x);
    std::vector<Pair> factor(const std::size_t x);

    void print_table();
};

#endif