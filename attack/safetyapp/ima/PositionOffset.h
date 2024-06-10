
#pragma once

#include <VANETSIMULATION/attack/safetyapp/ima/Interface.h>

namespace VANETSIMULATION {
namespace attack {
namespace safetyapp {
namespace ima {
class PositionOffset final : public Interface {
public:
    PositionOffset(bool const approachingIntersection);
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace VANETSIMULATION
