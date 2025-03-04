

#include <VANETSIMULATION/attack/heading/Perpendicular.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Heading.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {

void Perpendicular::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("PerpendicularHeading");
    bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + M_PI_2));
}

} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION