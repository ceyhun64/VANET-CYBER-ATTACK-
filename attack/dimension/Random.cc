

#include <VANETSIMULATION/attack/dimension/Random.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace VANETSIMULATION {
namespace attack {
namespace dimension {
void Random::attack(veins::BasicSafetyMessage* bsm)
{
    auto rng = getEnvir()->getRNG(0);

    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double const kLength{uniform(rng, -INFINITY, INFINITY)};
    double const kWidth{uniform(rng, -INFINITY, INFINITY)};

    setParams(bsm, "Random", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace VANETSIMULATION
