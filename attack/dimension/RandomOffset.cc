

#include <vasp/attack/dimension/RandomOffset.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace vasp {
namespace attack {
namespace dimension {
void RandomOffset::update(double const offset)
{
    offset_ = offset;
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{

    auto rng = getEnvir()->getRNG(0);

    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double const kLength{bsm->getLength() + uniform(rng, -offset_, offset_)};
    double const kWidth{bsm->getWidth() + uniform(rng, -offset_, offset_)};

    setParams(bsm, "RandomOffset", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace vasp
