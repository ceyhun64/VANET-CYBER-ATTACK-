

#pragma once

#include <VANETSIMULATION/attack/Interface.h>
#include <veins/base/utils/Coord.h>

namespace VANETSIMULATION {
namespace attack {
namespace mobility {
class CommRangeBraking final : public Interface {
public:
    CommRangeBraking(veins::BasicSafetyMessage const* rvBsm, double& distance, veins::Coord const& senderSpeed);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord ghostVehiclePos_{};
    veins::Coord senderSpeed_{};
};
} // namespace mobility
} // namespace attack
} // namespace VANETSIMULATION