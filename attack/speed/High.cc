
#include <vasp/attack/speed/High.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace speed {
void High::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("HighSpeed");

    // maximal speed as defined in ETSI TS 102 894-2: 163.82m/s
    bsm->setSenderSpeed(bsm->getHeading().toCoord() * 163.83);
}
} // namespace speed
} // namespace attack
} // namespace vasp