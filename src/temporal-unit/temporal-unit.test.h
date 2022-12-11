#pragma once

#include <tuple>
#include <gtest/gtest.h>

#include "temporal-unit.h"

class IsDateBasedTest : public testing::TestWithParam<tuple<TemporalUnit*, bool>> {};

class IsTimeBasedTest : public testing::TestWithParam<tuple<TemporalUnit*, bool>> {};

INSTANTIATE_TEST_SUITE_P(TemporalUnitTest,
	IsDateBasedTest,
	testing::Values(
		make_tuple(&TemporalUnit::of(NANOS), false),
		make_tuple(&TemporalUnit::of(MICROS), false),
		make_tuple(&TemporalUnit::of(MILLIS), false),
		make_tuple(&TemporalUnit::of(SECONDS), false),
		make_tuple(&TemporalUnit::of(MINUTES), false),
		make_tuple(&TemporalUnit::of(HOURS), false),
		make_tuple(&TemporalUnit::of(HALF_DAYS), false),
		make_tuple(&TemporalUnit::of(DAYS), true),
		make_tuple(&TemporalUnit::of(WEEKS), true),
		make_tuple(&TemporalUnit::of(MONTHS), true),
		make_tuple(&TemporalUnit::of(YEARS), true),
		make_tuple(&TemporalUnit::of(DECADES), true),
		make_tuple(&TemporalUnit::of(CENTURIES), true),
		make_tuple(&TemporalUnit::of(MILLENIA), true),
		make_tuple(&TemporalUnit::of(ERAS), true),
		make_tuple(&TemporalUnit::of(FOREVER), true)
	)
);

TEST_P(IsDateBasedTest, IsDateBasedTest) {
	auto param = GetParam();
	TemporalUnit& unit = *get<0>(param);
	ASSERT_EQ(unit.isDateBased(), get<1>(param));
}

INSTANTIATE_TEST_SUITE_P(TemporalUnitTest,
	IsTimeBasedTest,
	testing::Values(
		make_tuple(&TemporalUnit::of(NANOS), true),
		make_tuple(&TemporalUnit::of(MICROS), true),
		make_tuple(&TemporalUnit::of(MILLIS), true),
		make_tuple(&TemporalUnit::of(SECONDS), true),
		make_tuple(&TemporalUnit::of(MINUTES), true),
		make_tuple(&TemporalUnit::of(HOURS), true),
		make_tuple(&TemporalUnit::of(HALF_DAYS), true),
		make_tuple(&TemporalUnit::of(DAYS), false),
		make_tuple(&TemporalUnit::of(WEEKS), false),
		make_tuple(&TemporalUnit::of(MONTHS), false),
		make_tuple(&TemporalUnit::of(YEARS), false),
		make_tuple(&TemporalUnit::of(DECADES), false),
		make_tuple(&TemporalUnit::of(CENTURIES), false),
		make_tuple(&TemporalUnit::of(MILLENIA), false),
		make_tuple(&TemporalUnit::of(ERAS), false),
		make_tuple(&TemporalUnit::of(FOREVER), false)
	)
);

TEST_P(IsTimeBasedTest, IsTimeBasedTest) {
	auto param = GetParam();
	TemporalUnit& unit = *get<0>(param);
	ASSERT_EQ(unit.isTimeBased(), get<1>(param));
}

TEST(TemporalUnitTest, SameInstanceTest) {
	TemporalUnit* firstInstance = &TemporalUnit::of(SECONDS);
	TemporalUnit* secondInstance = &TemporalUnit::of(SECONDS);
	ASSERT_EQ(firstInstance, secondInstance);
}