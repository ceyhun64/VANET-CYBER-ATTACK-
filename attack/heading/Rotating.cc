

#include <VANETSIMULATION/attack/heading/Rotating.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Heading.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void Rotating::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RotatingHeading");
    bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + 0.1 * M_PI));
}

} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION