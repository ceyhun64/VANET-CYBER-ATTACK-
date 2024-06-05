

#pragma once

#include <vasp/attack/dimension/Interface.h>

namespace vasp {
namespace attack {
namespace dimension {
class High final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace dimension
} // namespace attack
} // namespace vasp
