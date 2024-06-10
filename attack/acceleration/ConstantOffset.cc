//iletişim engellem saldırısı

#include <VANETSIMULATION/attack/acceleration/ConstantOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
ConstantOffset::ConstantOffset(double const offset)
    : offset_(offset)
{
}

void ConstantOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantAccelerationOffset");
    bsm->setAcceleration(bsm->getAcceleration() + offset_);
}
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION