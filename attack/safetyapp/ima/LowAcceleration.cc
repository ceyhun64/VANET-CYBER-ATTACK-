

#include <vasp/attack/safetyapp/ima/LowAcceleration.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {

LowAcceleration::LowAcceleration(bool const approachingIntersection)
{
    approachingIntersection_ = approachingIntersection;
}

void LowAcceleration::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("IMALowAcceleration");
    bsm->setAcceleration(bsm->getAcceleration() - 100);
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
