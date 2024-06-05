

#include <vasp/attack/position/self_telemetry/SuddenDisappearance.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace position {

void SuddenDisappearance::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("SuddenDisappearance");
    delete bsm;
    bsm = nullptr;
}

} // namespace position
} // namespace attack
} // namespace vasp