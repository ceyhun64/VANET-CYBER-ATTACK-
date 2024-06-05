

#include <vasp/attack/safetyapp/eebl/StopAfterAttack.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Coord.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace eebl {

bool StopAfterAttack::attackFlag_ = false;

StopAfterAttack::StopAfterAttack(veins::BasicSafetyMessage const* rvBsm)
{
    if (!attackFlag_) {
        return;
    }

    auto constexpr ghostVehicleOffset = 0.2; // put ghost just within target's safety distance
    // calculate ghost vehicle's position w.r.t. target's safety distance
    ghostPos_ = utils::getPosOffset(rvBsm, ghostVehicleOffset);
    attackFlag_ = false;
}

void StopAfterAttack::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("FakeEEBLStopPositionUpdateAfterAttack");
    bsm->setSenderSpeed(veins::Coord::ZERO); // creates a speed object with speed = 0
    bsm->setEventHardBraking(true);
    bsm->setSenderPos(ghostPos_);

    // since FakeEEBL is sent, send the same position as that at previous transmission
    auto constexpr kXAccel = 4.6;
    bsm->setAcceleration(kXAccel);
}

} // namespace eebl
} // namespace safetyapp
} // namespace attack
} // namespace vasp