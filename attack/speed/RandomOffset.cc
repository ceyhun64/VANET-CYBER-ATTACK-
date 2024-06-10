

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <VANETSIMULATION/attack/speed/RandomOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace speed {
RandomOffset::RandomOffset(double const offset)
    : offset_(offset)
{
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomSpeedOffset");

    auto rng = getEnvir()->getRNG(0);
    bsm->setSenderSpeed(bsm->getSenderSpeed() + veins::Coord(uniform(rng, -offset_, offset_), uniform(rng, -offset_, offset_)));
}
} // namespace speed
} // namespace attack
} // namespace VANETSIMULATION