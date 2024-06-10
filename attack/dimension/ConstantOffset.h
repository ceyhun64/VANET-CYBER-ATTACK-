

#pragma once

#include <VANETSIMULATION/attack/dimension/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace dimension {
class ConstantOffset final : public Interface {
public:
    void update(double const offset);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double offset_;
};
} // namespace dimension
} // namespace attack
} // namespace VANETSIMULATION
