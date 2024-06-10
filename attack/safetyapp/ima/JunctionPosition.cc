

#include <VANETSIMULATION/attack/safetyapp/ima/JunctionPosition.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace safetyapp {
namespace ima {

JunctionPosition::JunctionPosition(bool const approachingIntersection, veins::Coord const& junctionPos)
    : junctionPos_(junctionPos)
{
    approachingIntersection_ = approachingIntersection;
}

void JunctionPosition::attack(veins::BasicSafetyMessage* bsm)
{
    if (approachingIntersection_) {
        bsm->setAttackType("JunctionPosition");
        bsm->setSenderPos(junctionPos_);
    }
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace VANETSIMULATION