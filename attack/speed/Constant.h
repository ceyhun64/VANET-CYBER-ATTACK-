

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace speed {
class Constant final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace speed
} // namespace attack
} // namespace VANETSIMULATION