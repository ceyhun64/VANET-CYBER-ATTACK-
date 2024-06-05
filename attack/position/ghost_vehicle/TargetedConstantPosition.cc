

#include <vasp/attack/position/ghost_vehicle/TargetedConstantPosition.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace attack {
namespace position {

TargetedConstantPosition::TargetedConstantPosition(veins::BasicSafetyMessage const* rvBsm, double const offset, veins::Coord& ghostPos, bool& attackFlag)
{
    if (attackFlag) {
        ghostPos = utils::getPosOffset(rvBsm, offset);
        attackFlag = false;
    }
    ghostPos_ = ghostPos;
}

void TargetedConstantPosition::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("TargetedConstantPosition");
    bsm->setData("ghost");
    bsm->setSenderSpeed(veins::Coord::ZERO);
    bsm->setSenderPos(ghostPos_);
}
} // namespace position
} // namespace attack
} // namespace vasp