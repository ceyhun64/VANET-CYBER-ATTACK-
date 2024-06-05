

#include <vasp/attack/safetyapp/ima/HighSpeed.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {

HighSpeed::HighSpeed(bool const approachingIntersection)
{
    approachingIntersection_ = approachingIntersection;
}

void HighSpeed::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("IMAHighSpeed");
    bsm->setSenderSpeed(bsm->getSenderSpeed() + bsm->getHeading().toCoord() * 100);
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
