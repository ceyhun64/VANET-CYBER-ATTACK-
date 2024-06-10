

#pragma once

#include <VANETSIMULATION/attack/Interface.h>
#include <veins/base/utils/Coord.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {
class SuddenAppearance final : public Interface {
public:
    SuddenAppearance(veins::BasicSafetyMessage const* rvBsm);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord posOffset_{};
};
} // namespace position
} // namespace attack
} // namespace VANETSIMULATION
