

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace speed {
class RandomOffset final : public Interface {
public:
    RandomOffset(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_{};
};
} // namespace speed
} // namespace attack
} // namespace VANETSIMULATION