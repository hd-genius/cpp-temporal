#pragma once

#include "temporal-unit.h"
#include "../duration.h"

namespace temporal {
	class SecondUnit : TemporalUnit {
	private:
		inline static TemporalUnit* instance = nullptr;

		SecondUnit();
	public:
		static TemporalUnit& getInstance();

		// long between(Temporal temporal1Inclusive, Temporal temporal2Exclusive) const;

		Duration getDuration() const;

		bool isDateBased() const;

		bool isDurationEstimated()const;

		// bool isSupportedBy(Temporal temporal) const;

		bool isTimeBased()const;
	};
}
