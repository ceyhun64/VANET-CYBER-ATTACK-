

#pragma once

#include <vasp/attack/safetyapp/ima/Interface.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {
class LowSpeed final : public Interface {
public:
    LowSpeed(bool const approachingIntersection);
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
