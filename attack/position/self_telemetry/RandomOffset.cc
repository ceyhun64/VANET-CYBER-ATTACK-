

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <veins/base/utils/Coord.h>
#include <VANETSIMULATION/attack/position/self_telemetry/RandomOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {

RandomOffset::RandomOffset(double const offset)
    : offset_(offset)
{
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{
    auto rng = getEnvir()->getRNG(0);

    bsm->setAttackType("RandomOffset");
    bsm->setSenderPos(bsm->getSenderPos() + veins::Coord(uniform(rng, -offset_, offset_), uniform(rng, -offset_, offset_)));
}

} // namespace position
} // namespace attack
} // namespace VANETSIMULATION