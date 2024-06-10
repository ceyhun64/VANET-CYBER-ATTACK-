

#include <VANETSIMULATION/attack/position/ghost_vehicle/SuddenAppearance.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <VANETSIMULATION/utils/SupportFunctions.h>

namespace VANETSIMULATION {
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
} // namespace VANETSIMULATION