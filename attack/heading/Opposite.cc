

#include <VANETSIMULATION/attack/heading/Opposite.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Heading.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void Opposite::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("OppositeHeading");
    bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + M_PI));
}

} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION