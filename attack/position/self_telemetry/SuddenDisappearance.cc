

#include <VANETSIMULATION/attack/position/self_telemetry/SuddenDisappearance.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
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
} // namespace VANETSIMULATION