

#pragma once

// forward declarations
namespace veins {
class BasicSafetyMessage;
} // namespace veins

namespace vasp {
namespace attack {
class Interface {
public:
    virtual void attack(veins::BasicSafetyMessage* bsm) = 0;
};
} // namespace attack
} // namespace vasp