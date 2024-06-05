
#include <veins/base/modules/BaseWorldUtility.h>
#include <vasp/attack/position/self_telemetry/Random.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
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
} // namespace vasp