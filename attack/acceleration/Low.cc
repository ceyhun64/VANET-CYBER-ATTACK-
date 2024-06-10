//düşük hızlanma atağı

#include <VANETSIMULATION/attack/acceleration/Low.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
void Low::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("LowAcceleration");

    // minimal acceleration as defined in ETSI TS 102 894-2: -16m/s^2
    bsm->setAcceleration(-16.5);
}
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION