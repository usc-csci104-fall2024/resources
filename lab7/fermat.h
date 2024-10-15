#pragma once

#include <cstdint>
#include <vector>

std::uint32_t mod_exp(std::uint32_t base, std::uint32_t exponent, std::uint32_t mod);

bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests);

