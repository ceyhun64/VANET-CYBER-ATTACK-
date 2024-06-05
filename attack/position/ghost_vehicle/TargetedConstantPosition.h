

#pragma once

#include <vasp/attack/Interface.h>
#include <veins/base/utils/Coord.h>

namespace vasp {
namespace attack {
namespace position {
class TargetedConstantPosition final : public Interface {
public:
    TargetedConstantPosition(veins::BasicSafetyMessage const* rvBsm, double const posOffset, veins::Coord& ghostPos, bool& attackFlag);
    void attack(veins::BasicSafetyMessage* bsm) override;

private:
    veins::Coord ghostPos_{};
};
} // namespace position
} // namespace attack
} // namespace vasp
