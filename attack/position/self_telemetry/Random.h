

#pragma once

#include <vasp/attack/Interface.h>

// forward declarations
namespace veins {
class BaseWorldUtility;
} // namespace veins

namespace vasp {
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
} // namespace vasp