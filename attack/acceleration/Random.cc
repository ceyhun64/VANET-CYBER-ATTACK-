//rastgele hızlanma

#include <VANETSIMULATION/attack/acceleration/Random.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
void Random::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomAcceleration");

    auto rng = getEnvir()->getRNG(0);
    bsm->setAcceleration(uniform(rng, -INFINITY, INFINITY));
}
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION