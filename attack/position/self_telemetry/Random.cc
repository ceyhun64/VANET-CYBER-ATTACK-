
#include <veins/base/modules/BaseWorldUtility.h>
#include <VANETSIMULATION/attack/position/self_telemetry/Random.h>
#include <VANETSIMULATION/messages/BasicSafetyMessage_m.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {

Random::Random(veins::BaseWorldUtility* world)
    : randomPosition_(world->getRandomPosition())
{
}

void Random::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("RandomPosition");
    bsm->setSenderPos(randomPosition_);
}

} // namespace position
} // namespace attack
} // namespace VANETSIMULATION