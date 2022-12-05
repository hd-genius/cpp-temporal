#include "temporal-unit.h"

TEST(TemporalUnit, IsDateBasedTest) {
	TemporalUnit& unit = TemporalUnit::of(SECONDS);
	ASSERT_EQ(unit.isDateBased(), false);
}

TEST(TemporalUnit, IsTimeBasedTest) {
	TemporalUnit& unit = TemporalUnit::of(SECONDS);
	ASSERT_EQ(unit.isTimeBased(), true);
}