#include "fermat.h"

#include <vector>
#include <cassert>
#include <random>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

// Calculates (base ^ exponent) % mod
std::uint32_t mod_exp(std::uint32_t base, std::uint32_t exponent, std::uint32_t mod) {
    throw std::runtime_error{"Not implemented"};
}

// Perform Fermat test on n.
// You should return true only if A^(n-1) % n == 1 for every A inside the tests vector
bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests) {
    throw std::runtime_error{"Not implemented"};
}

