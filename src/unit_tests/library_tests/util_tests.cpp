#include "pch.h"
#include "util/util.h"
#include "random_generator/lcg_generator.h"
#include "random_generator/tore_generator.h"

TEST(util, Vector) {
	Vector vector(3, new double[3] {10, 9, 6});
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

TEST(util, Cube) {
	Cube cube;
	cube.reSize(5, 3, 2);
	cube.get(1, 0, 1) = 4;
	cube.get(4, 2, 0) = 2;
	cube.get(1, 1, 1) = 9;
	cube.get(3, 0, 1) = 7;
	Cube copyCube(cube);
	Vector* vector = &cube;
	vector->itsArray[9] = 8;
	EXPECT_EQ(30, copyCube.itsSize);
	EXPECT_EQ(9, copyCube.get(1, 1, 1));
	EXPECT_EQ(8, cube.get(1, 1, 1));
	EXPECT_EQ(7, copyCube[19]);
}

TEST(random, LCG) {
	LCGGenerator lcg(10000);
	lcg.generateValues();
	Vector vector = *lcg.itsCube;
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

TEST(random, Tore) {
	ToreGenerator tore(10000);
	tore.generateValues();
	Cube cube = *tore.itsCube;

	EXPECT_EQ(0.61357464497618253, cube[23]);
	EXPECT_EQ(0.79660590622279415, cube[656]);
	EXPECT_EQ(0.39833478281070711, cube[9337]);
	EXPECT_EQ(0.54132577225755085, cube[2341]);
	double mean = cube.mean();
	EXPECT_EQ(0.50006717514021637, mean);
	double variance = cube.variance(mean);
	EXPECT_EQ(0.083332462913917993, variance);
	double skewness = cube.skewness(mean, variance);
	EXPECT_EQ(-1.0627240137327832e-05, skewness);
	double kurtosis = cube.kurtosis(mean, variance);
	EXPECT_EQ(-1.2000166145678635, kurtosis);
}