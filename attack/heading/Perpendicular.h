

#pragma once

#include <VANETSIMULATION/attack/heading/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace heading {
class Perpendicular final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace heading
} // namespace attack
} // namespace VANETSIMULATION