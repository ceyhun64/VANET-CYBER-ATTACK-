//güvenlik mesajlarının boyutlarını rastgele değiştirir

#include <vasp/attack/dimension/BadRatio.h>
#include <vasp/messages/BasicSafetyMessage_m.h>
#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>

namespace vasp {
namespace attack {
namespace dimension {
void BadRatio::attack(veins::BasicSafetyMessage* bsm)
{
    auto rng = getEnvir()->getRNG(0);

    // plausible length range: [0.1, 102.2]m [ETSI TS 102 894-2]
    // plausible width range: [0.1, 6.1]m [ETSI TS 102 894-2]
    double constexpr kMaxLength{102.2};
    double const kLength{bsm->getWidth() + uniform(rng, -(bsm->getWidth() - EPSILON), -EPSILON)};
    double const kWidth{bsm->getLength() + uniform(rng, EPSILON, (kMaxLength + EPSILON) - bsm->getLength())};

    setParams(bsm, "BadRatio", kLength, kWidth);
}
} // namespace dimension
} // namespace attack
} // namespace vasp
