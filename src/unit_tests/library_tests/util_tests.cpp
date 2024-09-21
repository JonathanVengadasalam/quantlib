#include "pch.h"
#include "util/util.h"
#include "random_generator/lcg_generator.h"

TEST(util, Vector) {
	Vector vector(3, new double[4] {10, 9, 6});
	vector.reSize(4, true);
	vector[3] = 7;
	vector.quickSort();
	vector.swap(1, 2);
	EXPECT_EQ(6, vector[0]);
	EXPECT_EQ(9, vector[1]);
	EXPECT_EQ(7, vector[2]);
	EXPECT_EQ(3, vector.maxIndex());
	double mean = vector.mean();
	double variance = vector.variance(mean);
	EXPECT_EQ(8, mean);
	EXPECT_EQ(2.5, variance);
	EXPECT_EQ(0., vector.skewness(mean, variance));
	EXPECT_EQ(-1.64, vector.kurtosis(mean, variance));
	EXPECT_TRUE(true);
}

TEST(random, LCG) {
	LCGGenerator lcg(10000);
	lcg.generateValues();
	Vector vector = *lcg.itsVector;
	EXPECT_EQ(0.83502077489859461, vector[10]);
	EXPECT_EQ(0.91840744620114911, vector[777]);
	EXPECT_EQ(0.069029708425062578, vector[9637]);
	EXPECT_EQ(0.74818784964652163, vector[5901]);

	double mean = vector.mean();
	EXPECT_EQ(0.50296822208346237, mean);
	double variance = vector.variance(mean);
	EXPECT_EQ(0.083070836165374834, variance);
	double skewness = vector.skewness(mean, variance);
	EXPECT_EQ(-0.022989838775216240, skewness);
	double kurtosis = vector.kurtosis(mean, variance);
	EXPECT_EQ(-1.2036993694102784, kurtosis);
}