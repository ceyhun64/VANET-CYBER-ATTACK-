

#pragma once

#include <vasp/attack/safetyapp/ima/Interface.h>
#include <veins/base/utils/Coord.h>

namespace vasp {
namespace attack {
namespace safetyapp {
namespace ima {
class JunctionPosition final : public Interface {
public:
    JunctionPosition(bool const approachingIntersection, veins::Coord const& junctionPos);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord junctionPos_{};
};
} // namespace ima
} // namespace safetyapp
} // namespace attack
} // namespace vasp