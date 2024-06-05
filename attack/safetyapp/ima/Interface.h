

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {
class Interface : public attack::Interface {
public:
    virtual void attack(veins::BasicSafetyMessage* bsm) override = 0;

protected:
    bool approachingIntersection_{false};
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp