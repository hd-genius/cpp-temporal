#pragma once

#include "../chrono-unit.h"
#include "../duration.h"

namespace temporal {
	class TemporalUnit {
	protected:
		const ChronoUnit unit;

		TemporalUnit(ChronoUnit unit);
	public:
		static TemporalUnit& of(const ChronoUnit);

		// virtual long between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const = 0;

		virtual Duration getDuration() const = 0;

		virtual bool isDateBased() const = 0;

		virtual bool isDurationEstimated() const = 0;

		// virtual bool isSupportedBy(Temporal temporal) const = 0;

		virtual bool isTimeBased() const = 0;

		bool operator==(TemporalUnit&) const;
	};
}


