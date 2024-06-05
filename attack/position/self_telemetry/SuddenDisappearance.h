

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace position {
class SuddenDisappearance final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace position
} // namespace attack
} // namespace vasp