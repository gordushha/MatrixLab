#include <../gtest/gtest.h>
#include "MyVector.h"
TEST(Vector, can_create_vector_with_defaul_construct)
{
  ASSERT_NO_THROW(Vector <int> v1);
}
TEST(Vector, Name2) {
  Vector <double> v1(5.1);


    EXPECT_EQ(1, v1.Length());
  EXPECT_EQ(5.1, v1[0]);
}
  TEST (Vector, can_create_copied_vector)
  {
    Vector<double> v(10);

    ASSERT_NO_THROW(Vector<double> v1(v));
  }
  
  TEST(Vector, can_get_size)
  {
    Vector<double> v1(10);

    EXPECT_EQ(1, v1.Length());
  }
  TEST(Vector, can_use_multiplication_for_vector)
  {
    Vector <int> v1(4, 2);
    Vector <int> v2(3, 7);

    Vector <int> v3 = v1 * v2;

    EXPECT_EQ(3, v3.Length());
    for (int i = 0; i < v3.Length(); i++)
      EXPECT_EQ(14, v3[i]);
  }
  TEST(Vector, Name3) {
    Vector<double>v1(5.1);


    EXPECT_EQ(1, v1.Length());
    for (int i = 0; i < v1.Length(); ++i)
      EXPECT_EQ(5.1, v1[0]);
  }
