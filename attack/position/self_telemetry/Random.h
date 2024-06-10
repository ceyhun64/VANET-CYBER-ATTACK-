

#pragma once

#include <VANETSIMULATION/attack/Interface.h>

// forward declarations
namespace veins {
class BaseWorldUtility;
} // namespace veins

namespace VANETSIMULATION {
namespace attack {
namespace position {
class Random final : public Interface {
public:
    Random(veins::BaseWorldUtility* world);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord randomPosition_{};
};
} // namespace position
} // namespace attack
} // namespace VANETSIMULATION