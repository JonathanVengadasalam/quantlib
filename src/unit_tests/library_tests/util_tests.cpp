#include "pch.h"
#include "util/util.h"

TEST(util, Vector) {
	Vector vector(4, new double[4] {10, 9, 6, 7});
	vector.quickSort();
  EXPECT_EQ(6, vector[0]);
  EXPECT_EQ(7, vector[1]);
  EXPECT_EQ(9, vector[2]);
  EXPECT_EQ(3, vector.maxIndex());
	double mean = vector.mean();
	double variance = vector.variance(mean);
  EXPECT_EQ(8, mean);
  EXPECT_EQ(2.5, variance);
  EXPECT_EQ(0., vector.skewness(mean, variance));
  EXPECT_EQ(-1.64, vector.kurtosis(mean, variance));
  EXPECT_TRUE(true);
}