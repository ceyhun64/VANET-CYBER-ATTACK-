

#pragma once

#include <vasp/attack/safetyapp/ima/Interface.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {
class HighSpeed final : public Interface {
public:
    HighSpeed(bool const approachingIntersection);
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp
