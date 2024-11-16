#include "pch.h"
#include "util/vector.h"
#include "random_generator/lcg_generator.h"
#include "random_generator/tore_generator.h"

TEST(util, Vector) {
	DblVector vector(3, new double[3] {10, 9, 6});
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
	DblVector secondVector(vector);
	EXPECT_TRUE(true);
}

TEST(util, Cube) {
	Cube cube;
	cube.reSize(5, 3, 2);
	cube.get(1, 0, 1) = 4;
	cube.get(4, 2, 0) = 2;
	cube.get(1, 1, 1) = 9;
	cube.get(3, 0, 1) = 7;
	Cube copyCube(cube, true);
	DblVector* vector = &cube;
	vector->itsArray[9] = 8;
	EXPECT_EQ(30, copyCube.itsSize);
	EXPECT_EQ(9, copyCube.get(1, 1, 1));
	EXPECT_EQ(8, cube.get(1, 1, 1));
	EXPECT_EQ(7, copyCube[19]);
}