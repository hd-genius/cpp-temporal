#include <gtest/gtest.h>

#include "duration.test.h"
#include "temporal-unit/temporal-unit.test.h"


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
