

#include <vasp/attack/heading/Rotating.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Heading.h>

namespace vasp {
namespace attack {
namespace heading {

void Rotating::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RotatingHeading");
    bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + 0.1 * M_PI));
}

} // namespace heading
} // namespace attack
} // namespace vasp