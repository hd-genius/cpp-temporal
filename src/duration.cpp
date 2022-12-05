#include <vector>

#include "duration.h"
#include "chrono-unit.h"

#define NANOS_TO_SECONDS 1000000000

using namespace std;

TemporalQuantity::TemporalQuantity(ChronoUnit unit, long quantity) : unit(unit), quantity(quantity) {}

Duration::Duration(vector<TemporalQuantity*> units) : unitLengths(units) {}

Duration::~Duration() {
	// TODO: implement
}

Duration Duration::ofZero() {
	return Duration(vector<TemporalQuantity*>());
}

Duration Duration::of(ChronoUnit unit, long quantity) {
	vector<TemporalQuantity*> quantities(1);
	quantities.push_back(new TemporalQuantity(unit, quantity));
	return Duration(quantities);
}

Duration Duration::of(ChronoUnit unit) {
	return Duration::of(unit, 1);
}

Duration Duration::operator+(Duration duration) const {
	return Duration::ofZero();
}

Duration Duration::operator-(Duration duration) const {
	return Duration::ofZero();
}

bool Duration::operator==(Duration duration) const {
	return false;
}

long Duration::get(ChronoUnit unit) const {
	for (const TemporalQuantity* quantity : unitLengths) {
		if (quantity->unit == unit) {
			return quantity->quantity;
		}
	}
	return 0;
}

long Duration::to(ChronoUnit unit) const {
	// convert all units to the target unit
	// sum all converted units
	// ensure that integer overflow does not occur
	return 0;
}
