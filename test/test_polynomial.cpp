#include <polynomial.h>

#include <gtest.h>


TEST(test_monomial, can_create_monomial_with_S)
{
    ASSERT_NO_THROW(monomial m(5, 200));
}

TEST(test_monomial, can_create_monomial_with_powers)
{
    ASSERT_NO_THROW(monomial m(5, 5, 6, 7));
}

TEST(test_monomial, cant_create_monomial_if_power_is_greater_than_the_maximum_power_1)
{
    ASSERT_ANY_THROW(monomial m(5, 5, 25, 7));
}

TEST(test_monomial, cant_create_monomial_if_power_is_greater_than_the_maximum_power_2)
{
    ASSERT_ANY_THROW(monomial m(5, 9261));
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
    monomial m3(0, 0);
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
    monomial m3(0, 0);
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
    monomial m3(0, 0);
    monomial m(25, 10, 12, 14);
    m3 = m1 * m2;
    EXPECT_EQ(m, m3);
    EXPECT_EQ(m.getCoeff(), m3.getCoeff());
}

TEST(test_monomial, can_multiply_monomials_2)
{
    monomial m1(5, 5, 6, 7);
    monomial m2(5, 5, 6, 7);
    monomial m3(0, 0);
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

TEST(test_monomial, can_change_the_sign_of_the_coefficient_monomials)
{
    monomial m(10, 5, 9, 7);
    m = -m;
    EXPECT_EQ(-10, m.getCoeff());
}

TEST(test_polynomial, can_create_polynomial)
{
    polynomial m;
    listIterator<monomial> iter = m.getIterBeginMonom();
    EXPECT_EQ(0, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(0, 0), iter.getValue());
}

TEST(test_polynomial, can_create_copied_polynomial)
{
    polynomial m;
    m += monomial(5, 345);
    polynomial m1(m);

    listIterator<monomial> iter1 = m.getIterBeginMonom();
    listIterator<monomial> iter2 = m1.getIterBeginMonom();

    EXPECT_EQ(5, iter2.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter2.getValue());
}

TEST(test_polynomial, can_get_iterator_to_begin_monom)
{
    polynomial m;
    m += monomial(5, 345);
    m += monomial(10, 2345);

    listIterator<monomial> iter = m.getIterBeginMonom();

    EXPECT_EQ(10, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(10, 2345), iter.getValue());
}

TEST(test_polynomial, can_get_iterator_to_end_monom)
{
    polynomial m;
    m += monomial(5, 345);
    m += monomial(10, 2345);

    listIterator<monomial> iter = m.getIterEndMonom();
    iter.prev();

    EXPECT_EQ(0, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(0, 0), iter.getValue());
}

TEST(test_polynomial, can_assign_polynomials)
{
    polynomial m;
    m += monomial(5, 345);
    polynomial m1;
    m1 = m;

    listIterator<monomial> iter1 = m.getIterBeginMonom();
    listIterator<monomial> iter2 = m1.getIterBeginMonom();

    EXPECT_EQ(5, iter2.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter2.getValue());
}

TEST(test_polynomial, can_multiply_by_a_scalar_1)
{
    listIterator<monomial> iter;
    polynomial m;
    m += monomial(5, 345);
    int scl = 10;
    m = m * scl;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(50, iter.getValue().getCoeff());
}


TEST(test_polynomial, can_multiply_by_a_scalar_2)
{
    listIterator<monomial> iter;
    polynomial m;
    m += monomial(5, 345);
    int scl = 10;
    m *= scl;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(50, iter.getValue().getCoeff());
}

TEST(test_polynomial, can_add_nomomial_1)
{
    listIterator<monomial> iter;
    polynomial m;
    monomial mon(5, 345);
    m = m + mon;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_add_nomomial_2)
{
    listIterator<monomial> iter;
    polynomial m;
    m += monomial(5, 345);
    iter = m.getIterBeginMonom();
    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_subtract_monomial_1)
{
    listIterator<monomial> iter;
    polynomial m;
    m = m - monomial(5, 345);
    iter = m.getIterBeginMonom();
    EXPECT_EQ(-5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_subtract_monomial_2)
{
    listIterator<monomial> iter;
    polynomial m;
    m -= monomial(5, 345);
    iter = m.getIterBeginMonom();
    EXPECT_EQ(-5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_multiply_monomial_1)
{
    listIterator<monomial> iter;
    polynomial m;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    m = m * monomial(3, 9, 7, 3);
    iter = m.getIterBeginMonom();
    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 14, 10, 10), iter.getValue());
    iter.next();

    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 10, 10, 12), iter.getValue());
}

TEST(test_polynomial, can_multiply_monomial_2)
{
    listIterator<monomial> iter;
    polynomial m;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    m *= monomial(3, 9, 7, 3);
    iter = m.getIterBeginMonom();
    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 14, 10, 10), iter.getValue());
    iter.next();

    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 10, 10, 12), iter.getValue());
}


TEST(test_polynomial, can_add_polynomials_1)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 345);
    m1 += monomial(10, 894);
    m += m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(10, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(10, 894), iter.getValue());
    iter.next();

    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_add_polynomials_2)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 345);
    m1 += monomial(10, 894);
    m = m + m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(10, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(10, 894), iter.getValue());
    iter.next();

    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_subtract_polynomials_1)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 345);
    m1 += monomial(10, 894);
    m -= m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(-10, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(-10, 894), iter.getValue());
    iter.next();

    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_subtract_polynomials_2)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 345);
    m1 += monomial(10, 894);
    m = m - m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(-10, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(10, 894), iter.getValue());
    iter.next();

    EXPECT_EQ(5, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(5, 345), iter.getValue());
}

TEST(test_polynomial, can_multiply_polynomials_1)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    m1 += monomial(3, 9, 7, 3);
    m1 += monomial(7, 7, 6, 5);
    m = m * m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 14, 10, 10), iter.getValue());
    iter.next();

    EXPECT_EQ(35, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(35, 12, 9, 12), iter.getValue());
    iter.next();

    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 10, 10, 12), iter.getValue());
    iter.next();

    EXPECT_EQ(35, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(35, 8, 9, 14), iter.getValue());
}

TEST(test_polynomial, can_multiply_polynomials_2)
{
    listIterator<monomial> iter;
    polynomial m, m1;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    m1 += monomial(3, 9, 7, 3);
    m1 += monomial(7, 7, 6, 5);
    m *= m1;
    iter = m.getIterBeginMonom();
    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 14, 10, 10), iter.getValue());
    iter.next();

    EXPECT_EQ(35, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(35, 12, 9, 12), iter.getValue());
    iter.next();

    EXPECT_EQ(15, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(15, 10, 10, 12), iter.getValue());
    iter.next();

    EXPECT_EQ(35, iter.getValue().getCoeff());
    EXPECT_EQ(monomial(35, 8, 9, 14), iter.getValue());
}

TEST(test_polynomial, cant_multiply_polynomials_if_resulting_power_exceeds_the_maximum)
{
    polynomial m, m1;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    m1 += monomial(3, 15, 7, 3);
    m1 += monomial(7, 7, 6, 5);
    m *= m1;
    ASSERT_ANY_THROW(m1 * m);
}

TEST(test_polynomial, can_get_the_value_of_a_polynomial_for_different_values_of_variables)
{
    polynomial m, m1;
    m += monomial(5, 5, 3, 7);
    m += monomial(5, 1, 3, 9);
    EXPECT_EQ(10444800, m.getValue(3, 4, 2));
}