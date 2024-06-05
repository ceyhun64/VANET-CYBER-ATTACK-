

#include <vasp/attack/speed/Constant.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace speed {
void Constant::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantSpeed");
    bsm->setSenderSpeed(bsm->getHeading().toCoord() * 5);
}
} // namespace speed
} // namespace attack
} // namespace vasp