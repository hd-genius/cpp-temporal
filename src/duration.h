#pragma once

#include <vector>

#include "chrono-unit.h"
#include "instant.h"

using namespace std;

namespace temporal {
    struct TemporalQuantity {
        const ChronoUnit unit;
        const long quantity;
        TemporalQuantity(ChronoUnit, long);
    };

    class Duration {
    private:
        const vector<TemporalQuantity*> unitLengths;

        Duration(vector<TemporalQuantity*>);

        const vector<ChronoUnit> getUnitTypes() const;
    public:
        static Duration ofZero();

        static Duration of(ChronoUnit);

        static Duration of(ChronoUnit, long);

        ~Duration();

        Duration operator+(Duration) const;

        Duration operator-(Duration) const;

        Duration operator*(long) const;

        Duration operator/(long) const;

        bool operator==(Duration) const;

        long get(ChronoUnit) const;

        long to(ChronoUnit) const;
    };
}
