

#include <vasp/attack/position/ghost_vehicle/SuddenAppearance.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace attack {
namespace position {

SuddenAppearance::SuddenAppearance(veins::BasicSafetyMessage const* rvBsm)
{
    // get target's safety distance
    auto const targetSafetyDistance = utils::getSafetyDistance(rvBsm->getSenderSpeed());
    // put ghost within target's safety distance
    auto const ghostVehicleOffset = targetSafetyDistance - 0.1;
    // calculate attacker's position w.r.t. target's safety distance
    posOffset_ = utils::getPosOffset(rvBsm, ghostVehicleOffset);
}

void SuddenAppearance::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("SuddenAppearance");
    bsm->setData("ghost");
    bsm->setSenderPos(posOffset_);
    bsm->setSenderSpeed(veins::Coord::ZERO);
}

} // namespace position
} // namespace attack
} // namespace vasp