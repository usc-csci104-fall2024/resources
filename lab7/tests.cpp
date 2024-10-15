#include "fermat.h"

#include <gtest/gtest.h>
#include <random>

constexpr int witness_count = 128;

std::vector<std::uint32_t> generate_witnesses(std::uint32_t n) {
    std::mt19937 rng(42);
    std::vector<uint32_t> result;
    std::uniform_int_distribution<std::uint32_t> dist(2, n - 1);
    result.reserve(witness_count);
    for (int i = 0; i < witness_count; ++i) {
        result.push_back(dist(rng));
    }
    return result;
}

bool do_fermat_test(std::uint32_t n) {
    return fermat_test(n, generate_witnesses(n));
}

TEST(Exponent, Exp_127_0_126) {
    ASSERT_EQ(mod_exp(5, 0, 126), 1);
}

TEST(Exponent, Exp_4294967293_2_4294967295) {
    ASSERT_EQ(mod_exp(4294967293, 2, 4294967295), 4);
}

TEST(Exponent, Exp_4294967293_2147483647_4294967295) {
    ASSERT_EQ(mod_exp(4294967293, 2147483647, 4294967295), 2147483647);
}

TEST(Exponent, Exp_4294967295_4294967295_4294967295) {
    ASSERT_EQ(mod_exp(4294967295, 4294967295, 4294967295), 0);
}

TEST(Exponent, Exp_8_2464_2465) {
    ASSERT_EQ(mod_exp(8, 2464, 2465), 1);
}

TEST(Fermat, Prime_197) {
    ASSERT_TRUE(do_fermat_test(197));
}

TEST(Fermat, Prime_5419) {
    ASSERT_TRUE(do_fermat_test(5419));
}

TEST(Fermat, Prime_51721) {
    ASSERT_TRUE(do_fermat_test(51721));
}

TEST(Fermat, Prime_1240232831) {
    ASSERT_TRUE(do_fermat_test(1240232831));
}

TEST(Fermat, Prime_1236508643) {
    ASSERT_TRUE(do_fermat_test(1236508643));
}

TEST(Fermat, Prime_195747077) {
    ASSERT_TRUE(do_fermat_test(195747077));
}

TEST(Fermat, Prime_3145246969) {
    ASSERT_TRUE(do_fermat_test(3145246969));
}

TEST(Fermat, Prime_2254467713) {
    ASSERT_TRUE(do_fermat_test(2254467713));
}

TEST(Fermat, Prime_2918303303) {
    ASSERT_TRUE(do_fermat_test(2918303303));
}

TEST(Fermat, Prime_2147483647) {
    ASSERT_TRUE(do_fermat_test(2147483647));
}

TEST(Fermat, NotPrime_12) {
    ASSERT_FALSE(do_fermat_test(12));
}

TEST(Fermat, NotPrime_36) {
    ASSERT_FALSE(do_fermat_test(36));
}

TEST(Fermat, NotPrime_7242141) {
    ASSERT_FALSE(do_fermat_test(7242141));
}

TEST(Fermat, NotPrime_187340887) {
    ASSERT_FALSE(do_fermat_test(187340887));
}

TEST(Fermat, NotPrime_798048287) {
    ASSERT_FALSE(do_fermat_test(798048287));
}

TEST(Fermat, NotPrime_1964714461) {
    ASSERT_FALSE(do_fermat_test(1964714461));
}

TEST(Fermat, NotPrime_18203) {
    ASSERT_FALSE(do_fermat_test(18203));
}
