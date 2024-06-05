

#include <vasp/attack/heading/Opposite.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <veins/base/utils/Heading.h>

namespace vasp {
namespace attack {
namespace heading {

void Opposite::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("OppositeHeading");
    bsm->setHeading(veins::Heading(bsm->getHeading().getRad() + M_PI));
}

} // namespace heading
} // namespace attack
} // namespace vasp