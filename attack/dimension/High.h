

#pragma once

#include <VANETSIMULATION/attack/dimension/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace dimension {
class High final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace dimension
} // namespace attack
} // namespace vaVANETSIMULATIONsp
