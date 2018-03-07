#include "person.hpp"
#include <gtest/gtest.h>

TEST(PersonCryingTest, ConstructingPerson) {
  Person p{};
  EXPECT_EQ(false, p.is_crying());
}

TEST(PersonCryingTest, UseCmake) {
  Person p{};
  EXPECT_EQ(false, p.is_crying());
  p.cry();
  EXPECT_EQ(true, p.is_crying());
}
