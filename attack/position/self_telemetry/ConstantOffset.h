

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {
class ConstantOffset final : public Interface {
public:
    ConstantOffset(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_{};
};
} // namespace position
} // namespace attack
} // namespace VANETSIMULATION