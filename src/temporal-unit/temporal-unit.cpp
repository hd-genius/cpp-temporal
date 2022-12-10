#include "temporal-unit.h"
#include "../chrono-unit.h"

using namespace temporal;

TemporalUnit& TemporalUnit::of(ChronoUnit unit) {
	TemporalUnit*& temporalUnit = unitCache[unit];
	if (temporalUnit == nullptr) {
		switch (unit) {
		case SECONDS:
			temporalUnit = new TemporalUnit(SECONDS, false, true, false);
			break;
		}
	}
	return *temporalUnit;
}

TemporalUnit::TemporalUnit(ChronoUnit unit, bool isDateBased, bool isTimeBased, bool isDurationEstimated) :
	unit(unit),
	_isDateBased(isDateBased) {}

// long SecondUnit::between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const;

Duration TemporalUnit::getDuration() const { return Duration::ofZero(); }

bool TemporalUnit::isDateBased() const {
	return _isDateBased;
}

bool TemporalUnit::isDurationEstimated() const {
	return false;
}

// bool SecondUnit::isSupportedBy(Temporal temporal) const;

bool TemporalUnit::isTimeBased() const {
	return true;
}

bool TemporalUnit::operator==(TemporalUnit& otherUnit) const {
	return otherUnit.unit == unit;
}
