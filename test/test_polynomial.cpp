#include <polynomial.h>

#include <gtest.h>


TEST(test_monomial, can_create_monomial)
{
    ASSERT_NO_THROW(monomial m);
}

TEST(test_monomial, can_create_monomial_with_power)
{
    ASSERT_NO_THROW(monomial m(5, 5, 6, 7));
}

TEST(test_monomial, cant_create_monomial_if_power_is_greater_than_the_maximum_power)
{
    ASSERT_ANY_THROW(monomial m(5, 5, 25, 7));
}

TEST(test_monomial, can_get_power_x)
{
    monomial m(5, 5, 6, 7);
    EXPECT_EQ(5, m.getX());
}

TEST(test_monomial, can_get_power_y)
{
    monomial m(5, 5, 6, 7);
    EXPECT_EQ(6, m.getY());
}

TEST(test_monomial, can_get_power_z)
{
    monomial m(5, 5, 6, 7);
    EXPECT_EQ(7, m.getZ());
}

TEST(test_monomial, can_get_coefficient)
{
    monomial m(5, 5, 6, 7);
    EXPECT_EQ(5, m.getCoeff());
}

TEST(test_monomial, can_compare_the_monomials_for_equality)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 == m2);
}

TEST(test_monomial, can_compare_the_monomials_on_inequality)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 != m2);
}

TEST(test_monomial, can_compare_the_monomials_less)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 6, 6, 8);
    EXPECT_EQ(true, m1 < m2);
}

TEST(test_monomial, can_compare_the_monomials_less_or_equal_1)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 6, 6, 8);
    EXPECT_EQ(true, m1 <= m2);
}

TEST(test_monomial, can_compare_the_monomials_less_or_equal_2)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 <= m2);
}

TEST(test_monomial, can_compare_the_monomials_greater)
{
    monomial m1(5, 6, 9, 7);
    monomial m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 > m2);
}

TEST(test_monomial, can_compare_the_monomials_greater_or_equal_1)
{
    monomial m1(5, 5, 9, 7);
    monomial m2(5, 5, 6, 8);
    EXPECT_EQ(true, m1 >= m2);
}

TEST(test_monomial, can_compare_the_monomials_greater_or_equal_2)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    EXPECT_EQ(true, m1 >= m2);
}

TEST(test_monomial, can_multiply_by_a_scalar_1)
{
    monomial m(5, 5, 6, 7);
    int scl = 10;
    m = m * scl;
    EXPECT_EQ(50, m.getCoeff());
}

TEST(test_monomial, can_multiply_by_a_scalar_2)
{
    monomial m(5, 5, 6, 7);
    int scl = 10;
    m *= scl;
    EXPECT_EQ(50, m.getCoeff());
}

TEST(test_monomial, can_add_monomials_1)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m3;
    m3 = m1 + m2;
    EXPECT_EQ(10, m3.getCoeff());
}

TEST(test_monomial, can_add_monomials_2)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m(5, 10, 12, 14);
    m1 += m2;
    EXPECT_EQ(10, m1.getCoeff());
}

TEST(test_monomial, cant_add_monomials_if_different_power_of_monomials)
{
    monomial m1(5, 5, 9, 7);
    monomial m2(5, 10, 6, 7);
    ASSERT_ANY_THROW(m1 + m2);
}

TEST(test_monomial, can_subtract_monomials_1)
{
    monomial m1(10, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m3;
    m3 = m1 - m2;
    EXPECT_EQ(5, m3.getCoeff());
}

TEST(test_monomial, can_subtract_monomials_2)
{
    monomial m1(10, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m(5, 10, 12, 14);
    m1 -= m2;
    EXPECT_EQ(5, m1.getCoeff());
}

TEST(test_monomial, cant_subtract_monomials_if_different_power_of_monomials)
{
    monomial m1(10, 5, 9, 7);
    monomial m2(5, 10, 6, 7);
    ASSERT_ANY_THROW(m1 - m2);
}

TEST(test_monomial, can_multiply_monomials_1)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m3;
    monomial m(25, 10, 12, 14);
    m3 = m1 * m2;
    EXPECT_EQ(m, m3);
    EXPECT_EQ(m.getCoeff(), m3.getCoeff());
}

TEST(test_monomial, can_multiply_monomials_2)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m3;
    monomial m(25, 10, 12, 14);
    m1 *= m2;
    EXPECT_EQ(m, m1);
    EXPECT_EQ(m.getCoeff(), m1.getCoeff());
}

TEST(test_monomial, cant_multiply_monomials_if_resulting_power_exceeds_the_maximum)
{
    monomial m1(10, 5, 17, 7);
    monomial m2(5, 10, 6, 5);
    ASSERT_ANY_THROW(m1 * m2);
}