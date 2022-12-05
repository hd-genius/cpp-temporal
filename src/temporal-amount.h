#pragma once

#include <list>
#include "temporal-unit.h"

namespace temporal {
    class TemporalAmount {
        virtual long get(TemporalUnit) = 0;

        virtual List<TemporalUnit> getUnits() = 0;
    };
}
