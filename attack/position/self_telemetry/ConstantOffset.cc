
#include <VANETSIMULATION/attack/position/self_telemetry/ConstantOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {

ConstantOffset::ConstantOffset(double const offset)
    : offset_(offset)
{
}

void ConstantOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantOffset");
    bsm->setSenderPos(bsm->getSenderPos() + veins::Coord(offset_, offset_));
}

} // namespace position
} // namespace attack
} // namespace VANETSIMULATION