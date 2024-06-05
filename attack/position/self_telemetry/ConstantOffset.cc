
#include <vasp/attack/position/self_telemetry/ConstantOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp