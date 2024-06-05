

#include <vasp/attack/safetyapp/eebl/JustAttack.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace eebl {

JustAttack::JustAttack(veins::BasicSafetyMessage const* rvBsm)
    : ghostPos_(utils::getPosOffset(rvBsm, kGhostVehicleOffset_))
{
}

void JustAttack::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("FakeEEBLJustAttack");
    bsm->setData("ghost");
    bsm->setSenderPos(ghostPos_);
    bsm->setSenderSpeed(veins::Coord::ZERO); // creates a speed object with speed = 0
    bsm->setEventHardBraking(true);

    auto constexpr kXAccel = 4.6;
    bsm->setAcceleration(kXAccel);
}

} // namespace eebl
} // namespace safetyapp
} // namespace attack
} // namespace vasp