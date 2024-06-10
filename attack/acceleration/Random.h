

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace acceleration {
class Random final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace acceleration
} // namespace attack
} // namespace VANETSIMULATION