

#pragma once

#include <vasp/attack/heading/Interface.h>

namespace vasp {
namespace attack {
namespace heading {
class Perpendicular final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace heading
} // namespace attack
} // namespace vasp