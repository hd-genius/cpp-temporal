#pragma once

#include <tuple>
#include <gtest/gtest.h>

#include "temporal-unit.h"

class IsDateBasedTest : public testing::TestWithParam<tuple<TemporalUnit*, bool>> {};

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

TEST(TemporalUnitTest, IsTimeBasedTest) {
	TemporalUnit& unit = TemporalUnit::of(SECONDS);
	ASSERT_EQ(unit.isTimeBased(), true);
}