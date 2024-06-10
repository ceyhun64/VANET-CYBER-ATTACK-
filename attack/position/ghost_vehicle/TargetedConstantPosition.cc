

#include <VANETSIMULATION/attack/position/ghost_vehicle/TargetedConstantPosition.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <VANETSIMULATION/utils/SupportFunctions.h>

namespace VANETSIMULATION {
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
} // namespace VANETSIMULATION