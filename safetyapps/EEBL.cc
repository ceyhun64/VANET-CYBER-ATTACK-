

#include <veins/base/utils/Coord.h>
#include <veins/base/utils/Heading.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <vasp/safetyapps/EEBL.h>
#include <vasp/utils/SupportFunctions.h>

namespace vasp {
namespace safetyapps {

// EEBL application implemented as defined in SAE J2945/1 standard
bool EEBL::warning(
    veins::BasicSafetyMessage const* bsm,
    veins::Coord const& myPos,
    veins::Heading const& myDirection,
    veins::Coord const& mySpeed,
    int const myId)
{
    if (!bsm->getEventHardBraking()) {
        return false;
    }

    auto isSenderBehind = utils::isBehind(myPos, bsm->getSenderPos(), myDirection);
    if (isSenderBehind) {
        return false;
    }

    // J2945/1 mentions that an EEBL is raised "if the distance between the vehicles is less than an
    // implementation-specific threshold value." Here the threshold value is the normal stopping
    // distance based on speed.
    if (myPos.distance(bsm->getSenderPos()) > utils::getSafetyDistance(mySpeed)) {
        return false;
    }

    return true;
}

} // namespace safetyapps
} // namespace vasp
