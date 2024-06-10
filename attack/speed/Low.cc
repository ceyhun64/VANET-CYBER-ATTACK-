

#include <VANETSIMULATION/attack/speed/Low.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace speed {
void Low::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("LowSpeed");

    // minimal speed as defined in ETSI TS 102 894-2: 0m/s
    bsm->setSenderSpeed(bsm->getHeading().toCoord() * -0.1);
}
} // namespace speed
} // namespace attack
} // namespace VANETSIMULATION