

#pragma once

#include <vasp/attack/Interface.h>
#include <veins/base/utils/Coord.h>

namespace vasp {
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
} // namespace vasp