//iletişim engellem saldırısı

#include <vasp/attack/acceleration/ConstantOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp