#include "SieveOfEratosthenes.hpp"

#include <cstdio>

using ll = long long int;


SieveOfEratosthenes::SieveOfEratosthenes(const size_t n) : n(n), table(n + 1, 0)
{
    for (int i = 2; i <= (int)n; i++) {
        if (table[i]) continue;
        primes.push_back(i);
        table[i] = i;
        for (ll j = i * i; j <= (int)n; j += i) {
            if (!table[j]) table[j] = i;
        }
    }
};


std::vector<int> SieveOfEratosthenes::factors(size_t x)
{
    std::vector<int> fs;
    if (!x) return fs;
    while (x != 1) {
        fs.push_back(table[x]);
        x /= table[x];
    }

    return fs;
};


bool SieveOfEratosthenes::is_prime(const size_t x)
{
    if (x == 0 or x == 1) return false;
    return x == (unsigned int) table[x];
};


std::vector<Pair> SieveOfEratosthenes::factor(const size_t x)
{
    std::vector<int> fs = factors(x);
    if (!fs.size()) return {};

    std::vector<Pair> dict_fs(1, Pair(fs.at(0), 0));
    for (const auto& f: fs) {
        if (dict_fs.back().first == f) dict_fs.back().second++;
        else dict_fs.emplace_back(f, 1);
    }

    return dict_fs;
};

void SieveOfEratosthenes::print_table()
{
    for (size_t i = 1; i < table.size(); i++) {
        printf("%3d", table[i]);
        if (!(i % 10)) printf("\n");
        else printf(" ");
    }
}