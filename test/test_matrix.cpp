#include <../gtest/gtest.h>
#include <MyMatrix.h>


TEST(Matrix, can_create_copied_matrix)
{
  Matrix<int> m(5);

  ASSERT_NO_THROW(Matrix<int> m1(m));
}
TEST(Matrix, can_not_use_plus_with_not_equal_size_of_matrix)
{
	Matrix<int> m1(2);
	Matrix<int> m2(5);
	Matrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 + m2);
}
TEST(Matrix, can_not_use_minus_with_not_equal_size_of_matrix)
{
	Matrix<int> m1(2);
	Matrix<int> m2(5);
	Matrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1 + m2);
}
TEST(Matrix, can_not_use_mult_with_not_equal_size_of_matrix)
{
	Matrix<int> m1(2);
	Matrix<int> m2(5);
	Matrix<int> m3;

	ASSERT_ANY_THROW(m3 = m1*m2);
}
