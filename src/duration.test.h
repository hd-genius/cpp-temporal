#pragma once

#include <tuple>
#include <gtest/gtest.h>
#include "duration.h"
#include "temporal-unit/temporal-unit.h"

using namespace std;


class DurationConversionTest : public testing::TestWithParam<tuple<Duration, long (*)(Duration), long>> {};

class DurationOperationTest : public testing::TestWithParam<tuple<Duration, Duration, Duration>> {};

INSTANTIATE_TEST_SUITE_P(DurationTest,
	DurationConversionTest,
	testing::Values(
		make_tuple(
			Duration::ofZero(),
			[](Duration duration) { return duration.to(NANOS); },
			0
		),
		make_tuple(
			Duration::of(NANOS, 50),
			[](Duration duration) { return duration.to(NANOS); },
			50
		),
		make_tuple(
			Duration::of(NANOS, -50),
			[](Duration duration) { return duration.to(NANOS); },
			-50
		),
		make_tuple(
			Duration::of(SECONDS),
			[](Duration duration) { return duration.to(NANOS); },
			1000000000
		),
		make_tuple(
			Duration::of(NANOS, 1000000000),
			[](Duration duration) { return duration.to(SECONDS); },
			1
		)
	)
);

TEST_P(DurationConversionTest, DurationConversionTest) {
	auto param = GetParam();
	Duration duration = get<0>(param);
	long (*durationAccessor)(Duration) = get<1>(param);
	long expectedDuration = get<2>(param);
	ASSERT_EQ(durationAccessor(duration), expectedDuration);
}

INSTANTIATE_TEST_SUITE_P(DurationAddTest,
	DurationOperationTest,
	testing::Values(
		make_tuple(
			Duration::of(NANOS, 50),
			Duration::of(NANOS, 100),
			Duration::of(NANOS, 50)
		),
		make_tuple(
			Duration::of(NANOS, 500000000),
			Duration::of(NANOS, 500000000),
			Duration::of(SECONDS, 1)
		),
		make_tuple(
			Duration::of(NANOS, 1000000000),
			Duration::of(NANOS, 1),
			Duration::of(NANOS, 1000000001)
		)
	)
);

TEST_P(DurationOperationTest, AddTest) {
	auto param = GetParam();
	Duration duration1 = get<0>(param);
	Duration duration2 = get<1>(param);
	Duration expectedDuration = get<2>(param);
	Duration result = duration1 + duration2;
	ASSERT_EQ(result, expectedDuration);
}

INSTANTIATE_TEST_SUITE_P(DurationSubtractTest,
	DurationOperationTest,
	testing::Values(
		make_tuple(
			Duration::of(NANOS, 100),
			Duration::of(NANOS, 50),
			Duration::of(NANOS, 50)
		),
		make_tuple(
			Duration::of(SECONDS, 1),
			Duration::of(NANOS, 500000000),
			Duration::of(NANOS, 500000000)
		),
		make_tuple(
			Duration::of(SECONDS, 1000000000),
			Duration::of(NANOS),
			Duration::of(NANOS, 999999999)
		)
	)
);

TEST_P(DurationOperationTest, SubtractTest) {
	auto param = GetParam();
	Duration duration1 = get<0>(param);
	Duration duration2 = get<1>(param);
	Duration expectedDuration = get<2>(param);
	Duration result = duration1 - duration2;
	ASSERT_EQ(result, expectedDuration);
}

/*
TEST_P(DurationDialationTest, MultiplyTest) {
	auto param = GetParam();
	Duration duration1 = get<0>(param);
	Duration duration2 = get<1>(param);
	Duration expectedDuration = get<2>(param);
	Duration result = duration1 * duration2;
	ASSERT_EQ(result, expectedDuration);
}
*/
