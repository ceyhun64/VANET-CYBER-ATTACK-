

#include <vasp/attack/mobility/CommRangeBraking.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace attack {
namespace mobility {

CommRangeBraking::CommRangeBraking(
    veins::BasicSafetyMessage const* rvBsm,
    double& distance,
    veins::Coord const& senderSpeed)
    : ghostVehiclePos_{utils::getPosOffset(rvBsm, distance)}
    , senderSpeed_(senderSpeed)
{
    // keep ghost vehicle from going behind target vehicle
    if (distance > 5) {
        distance -= 5;
    }
}

void CommRangeBraking::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setData("ghost");
    bsm->setAttackType("CommRangeBraking");
    bsm->setSenderPos(ghostVehiclePos_);
    bsm->setSenderSpeed(senderSpeed_);
}

} // namespace mobility
} // namespace attack
} // namespace vasp