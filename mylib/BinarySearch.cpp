#include "BinarySearch.hpp"


ll binary_search(ll left, ll right, std::vector<ll> a, ll key)
{
    ll mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        if (a[mid] >= key) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
};
