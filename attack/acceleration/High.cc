//yüksek hızlanma atağı

#include <vasp/attack/acceleration/High.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace acceleration {
void High::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("HighAcceleration");

    // maximal acceleration as defined in ETSI TS 102 894-2: 16m/s^2
    bsm->setAcceleration(16.5);
}
} // namespace acceleration
} // namespace attack
} // namespace vasp