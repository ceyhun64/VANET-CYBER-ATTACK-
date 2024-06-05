

#include <vasp/attack/safetyapp/ima/LowSpeed.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {

LowSpeed::LowSpeed(bool const approachingIntersection)
{
    approachingIntersection_ = approachingIntersection;
}

void LowSpeed::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("IMALowSpeed");
    bsm->setSenderSpeed(bsm->getSenderSpeed() - bsm->getHeading().toCoord() * 100);
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
