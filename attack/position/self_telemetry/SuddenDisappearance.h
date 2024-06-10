

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace position {
class SuddenDisappearance final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace position
} // namespace attack
} // namespace VANETSIMULATION