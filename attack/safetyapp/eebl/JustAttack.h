

#pragma once

#include <veins/base/utils/Coord.h>
#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace safetyapp {
namespace eebl {
class JustAttack final : public Interface {
public:
    JustAttack(veins::BasicSafetyMessage const* rvBsm);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    double const kGhostVehicleOffset_{0.2};
    veins::Coord ghostPos_{};
};
} // namespace eebl
} // namespace safetyapp
} // namespace attack
} // namespace VANETSIMULATION
