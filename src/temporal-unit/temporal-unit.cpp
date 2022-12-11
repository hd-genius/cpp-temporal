#include "temporal-unit.h"
#include "../chrono-unit.h"

using namespace temporal;

TemporalUnit* TemporalUnit::unitCache[CHRONO_UNIT_COUNT];

/// <summary>
/// The factory method and accessor for the available TemporalUnit instances
/// </summary>
/// <param name="unit"></param>
/// <returns>A a reference to the TemporalUnit representation of the given ChronoUnit</returns>
TemporalUnit& TemporalUnit::of(ChronoUnit unit) {
	TemporalUnit*& temporalUnit = unitCache[unit];
	if (temporalUnit == nullptr) {
		switch (unit) {
		case NANOS:
			temporalUnit = new TemporalUnit(NANOS, true, false);
			break;
		case MICROS:
			temporalUnit = new TemporalUnit(NANOS, true, false);
			break;
		case MILLIS:
			temporalUnit = new TemporalUnit(NANOS, true, false);
			break;
		case SECONDS:
			temporalUnit = new TemporalUnit(SECONDS, true, false);
			break;
		case MINUTES:
			temporalUnit = new TemporalUnit(MINUTES, true, false);
			break;
		case HOURS:
			temporalUnit = new TemporalUnit(HOURS, true, false);
			break;
		case HALF_DAYS:
			temporalUnit = new TemporalUnit(HALF_DAYS, true, false);
			break;
		case DAYS:
			temporalUnit = new TemporalUnit(DAYS,false, false);
			break;
		case WEEKS:
			temporalUnit = new TemporalUnit(WEEKS,false, false);
			break;
		case MONTHS:
			temporalUnit = new TemporalUnit(MONTHS,false, true);
			break;
		case YEARS:
			temporalUnit = new TemporalUnit(YEARS,false, true);
			break;
		case DECADES:
			temporalUnit = new TemporalUnit(DECADES,false, true);
			break;
		case CENTURIES:
			temporalUnit = new TemporalUnit(CENTURIES,false, true);
			break;
		case MILLENIA:
			temporalUnit = new TemporalUnit(MILLENIA,false, true);
			break;
		case ERAS:
			temporalUnit = new TemporalUnit(ERAS,false, true);
			break;
		case FOREVER:
			temporalUnit = new TemporalUnit(FOREVER,false, true);
			break;
		}
	}
	return *temporalUnit;
}

TemporalUnit::TemporalUnit(ChronoUnit unit, bool isTimeBased, bool isDurationEstimated) :
	unit(unit),
	_isTimeBased(isTimeBased) {}

// long SecondUnit::between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const;

Duration TemporalUnit::getDuration() const { return Duration::ofZero(); }

bool TemporalUnit::isDateBased() const {
	return !_isTimeBased;
}

bool TemporalUnit::isDurationEstimated() const {
	return false;
}

// bool SecondUnit::isSupportedBy(Temporal temporal) const;

bool TemporalUnit::isTimeBased() const {
	return _isTimeBased;
}

bool TemporalUnit::operator==(TemporalUnit& otherUnit) const {
	return otherUnit.unit == unit;
}
