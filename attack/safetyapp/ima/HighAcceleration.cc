

#include <VANETSIMULATION/attack/safetyapp/ima/HighAcceleration.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace safetyapp {
namespace ima {

HighAcceleration::HighAcceleration(bool const approachingIntersection)
{
    approachingIntersection_ = approachingIntersection;
}

void HighAcceleration::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("IMAHighAcceleration");
    bsm->setAcceleration(bsm->getAcceleration() + 100);
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace VANETSIMULATION
