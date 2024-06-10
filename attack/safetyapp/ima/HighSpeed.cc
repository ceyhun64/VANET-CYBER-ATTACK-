

#include <VANETSIMULATION/attack/safetyapp/ima/HighSpeed.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
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
} // namespace VANETSIMULATION
