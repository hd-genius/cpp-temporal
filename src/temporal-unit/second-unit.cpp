#include "second-unit.h"

TemporalUnit& SecondUnit::getInstance() {
	if (instance == nullptr) {
		instance = new SecondUnit();
	}
	return *instance;
}

SecondUnit::SecondUnit() : TemporalUnit(SECONDS) {}

// long SecondUnit::between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const;

Duration SecondUnit::getDuration() const { return Duration::ofZero(); }

bool SecondUnit::isDateBased() const {
	return false;
}

bool SecondUnit::isDurationEstimated() const {
	return false;
}

// bool SecondUnit::isSupportedBy(Temporal temporal) const;

bool SecondUnit::isTimeBased() const {
	return true;
}