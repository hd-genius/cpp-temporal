#include "temporal-unit.h"
#include "second-unit.h"
#include "../chrono-unit.h"

using namespace temporal;

TemporalUnit::TemporalUnit(ChronoUnit unit) : unit(unit) {}

TemporalUnit& TemporalUnit::of(const ChronoUnit unit) {
	switch (unit) {
	case SECONDS:
		return SecondUnit::getInstance();
	default:
		throw 1; // TODO: remove error once all cases are added
	}
}

bool TemporalUnit::operator==(TemporalUnit& otherUnit) const {
	return otherUnit.unit == unit;
}
