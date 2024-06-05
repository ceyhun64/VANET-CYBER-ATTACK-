

#pragma once

#include <vasp/attack/safetyapp/ima/Interface.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {
class LowAcceleration final : public Interface {
public:
    LowAcceleration(bool const approachingIntersection);
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
