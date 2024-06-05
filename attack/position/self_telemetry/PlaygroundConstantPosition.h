

#pragma once

#include <veins/base/utils/Coord.h>
#include <vasp/attack/Interface.h>

namespace veins {
class BaseWorldUtility;
} // namespace veins

namespace vasp {
namespace attack {
namespace position {

class PlaygroundConstantPosition final : public Interface {
public:
    PlaygroundConstantPosition(veins::BaseWorldUtility* world);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord playgroundSize_{};
};

} // namespace position
} // namespace attack
} // namespace vasp