#include <gtest/gtest.h>

#include "sample/sample.h"

namespace sample {

TEST(Sample, Parse) {
  EXPECT_EQ(Sample::Parse(""), 0);
  EXPECT_EQ(Sample::Parse("("), 1);
  EXPECT_EQ(Sample::Parse("(((("), 4);
  EXPECT_EQ(Sample::Parse(".(((("), 0);
  EXPECT_EQ(Sample::Parse("((.(("), 2);
}

}  // namespace sample