

#pragma once

#include <veins/base/utils/Coord.h>
#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace safetyapp {
namespace eebl {
class StopAfterAttack final : public Interface {
public:
    StopAfterAttack(veins::BasicSafetyMessage const* rvBsm);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    static bool attackFlag_;
    veins::Coord ghostPos_{};
};
} // namespace eebl
} // namespace safetyapp
} // namespace attack
} // namespace VANETSIMULATION
