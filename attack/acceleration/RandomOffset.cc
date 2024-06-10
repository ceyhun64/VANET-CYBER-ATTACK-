//araçlara rastgele ivme gönderme saldırısı

#include <omnetpp/csimulation.h>
#include <omnetpp/distrib.h>
#include <VANETSIMULATION/attack/acceleration/RandomOffset.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
RandomOffset::RandomOffset(double const offset)
    : offset_(offset)
{
}

void RandomOffset::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomAccelerationOffset");

    auto rng = getEnvir()->getRNG(0);
    bsm->setAcceleration(bsm->getAcceleration() + uniform(rng, -offset_, offset_));
}
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION