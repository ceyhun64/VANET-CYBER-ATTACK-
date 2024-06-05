//rastgele hızlanma

#include <vasp/attack/acceleration/Random.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace vasp {
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
} // namespace vasp