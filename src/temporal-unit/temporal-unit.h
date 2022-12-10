#pragma once

#include "../chrono-unit.h"
#include "../duration.h"

namespace temporal {
	class TemporalUnit {
	private:
		static TemporalUnit* unitCache[CHRONO_UNIT_COUNT];

		const ChronoUnit unit;

		const bool _isDateBased;

		TemporalUnit(ChronoUnit, bool, bool, bool);
	public:
		static TemporalUnit& of(ChronoUnit);

		// long between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const;

		Duration getDuration() const;

		bool isDateBased() const;

		bool isDurationEstimated() const;

		// bool isSupportedBy(Temporal temporal) const;

		bool isTimeBased() const;

		bool operator==(TemporalUnit&) const;
	};
}


