

#include <VANETSIMULATION/attack/speed/Constant.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace speed {
void Constant::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("ConstantSpeed");
    bsm->setSenderSpeed(bsm->getHeading().toCoord() * 5);
}
} // namespace speed
} // namespace attack
} // namespace VANETSIMULATION