

#include <vasp/attack/safetyapp/ima/PositionOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {

PositionOffset::PositionOffset(bool const approachingIntersection)
{
    approachingIntersection_ = approachingIntersection;
}

void PositionOffset::attack(veins::BasicSafetyMessage* bsm)
{
    if (approachingIntersection_) {
        bsm->setAttackType("IMAPositionOffset");
        bsm->setSenderPos(bsm->getSenderPos() + bsm->getHeading().toCoord() * 100);
    }
}

} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
