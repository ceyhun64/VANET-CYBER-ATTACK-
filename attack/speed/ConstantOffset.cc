
#include <vasp/attack/speed/ConstantOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace speed {
ConstantOffset::ConstantOffset(double const offset)
    : offset_(offset)
{
}

void ConstantOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantSpeedOffset");
    bsm->setSenderSpeed(bsm->getSenderSpeed() + veins::Coord(offset_, offset_));
}
} // namespace speed
} // namespace attack
} // namespace vasp