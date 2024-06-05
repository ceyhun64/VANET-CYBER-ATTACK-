

#include <vasp/attack/speed/Random.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace vasp {
namespace attack {
namespace speed {
void Random::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomSpeed");

    auto rng = getEnvir()->getRNG(0);
    bsm->setSenderSpeed(veins::Coord(uniform(rng, -INFINITY, INFINITY), uniform(rng, -INFINITY, INFINITY)));
}
} // namespace speed
} // namespace attack
} // namespace vasp