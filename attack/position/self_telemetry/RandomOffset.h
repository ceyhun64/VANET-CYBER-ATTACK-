
#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {
class RandomOffset final : public Interface {
public:
    RandomOffset(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_;
};
} // namespace position
} // namespace attack
} // namespace VANETSIMULATION