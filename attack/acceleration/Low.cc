//düşük hızlanma atağı

#include <vasp/attack/acceleration/Low.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp