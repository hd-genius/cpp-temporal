#include "temporal-unit.h"
#include "../chrono-unit.h"

using namespace temporal;

TemporalUnit& TemporalUnit::of(ChronoUnit unit) {
	TemporalUnit*& temporalUnit = unitCache[unit];
	if (temporalUnit == nullptr) {
		switch (unit) {
		case NANOS:
			temporalUnit = new TemporalUnit(NANOS, false, true, false);
			break;
		case MICROS:
			temporalUnit = new TemporalUnit(NANOS, false, true, false);
			break;
		case MILLIS:
			temporalUnit = new TemporalUnit(NANOS, false, true, false);
			break;
		case SECONDS:
			temporalUnit = new TemporalUnit(SECONDS, false, true, false);
			break;
		case MINUTES:
			temporalUnit = new TemporalUnit(MINUTES, false, true, false);
			break;
		case HOURS:
			temporalUnit = new TemporalUnit(HOURS, false, true, false);
			break;
		case HALF_DAYS:
			temporalUnit = new TemporalUnit(HALF_DAYS, false, true, false);
			break;
		case DAYS:
			temporalUnit = new TemporalUnit(DAYS, true, false, false);
			break;
		case WEEKS:
			temporalUnit = new TemporalUnit(WEEKS, true, false, false);
			break;
		case MONTHS:
			temporalUnit = new TemporalUnit(MONTHS, true, false, true);
			break;
		case YEARS:
			temporalUnit = new TemporalUnit(YEARS, true, false, true);
			break;
		case DECADES:
			temporalUnit = new TemporalUnit(DECADES, true, false, true);
			break;
		case CENTURIES:
			temporalUnit = new TemporalUnit(CENTURIES, true, false, true);
			break;
		case MILLENIA:
			temporalUnit = new TemporalUnit(MILLENIA, true, false, true);
			break;
		case ERAS:
			temporalUnit = new TemporalUnit(ERAS, true, false, true);
			break;
		case FOREVER:
			temporalUnit = new TemporalUnit(FOREVER, true, false, true);
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
