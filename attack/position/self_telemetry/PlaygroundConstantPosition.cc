
#include <veins/base/modules/BaseWorldUtility.h>
#include <vasp/attack/position/self_telemetry/PlaygroundConstantPosition.h>
#include <vasp/messages/BasicSafetyMessage_m.h>

namespace vasp {
namespace attack {
namespace position {

PlaygroundConstantPosition::PlaygroundConstantPosition(veins::BaseWorldUtility* world)
    : playgroundSize_(*(world->getPgs()))
{
}

void PlaygroundConstantPosition::attack(veins::BasicSafetyMessage* bsm)
{
    bsm->setAttackType("PlaygroundConstantPosition");
    bsm->setSenderPos(playgroundSize_ / 2);
}

} // namespace position
} // namespace attack
} // namespace vasp