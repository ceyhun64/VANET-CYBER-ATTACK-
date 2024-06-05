

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <veins/base/utils/Coord.h>
#include <vasp/attack/position/self_telemetry/RandomOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp