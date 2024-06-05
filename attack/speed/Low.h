

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace speed {
class Low final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace speed
} // namespace attack
} // namespace vasp