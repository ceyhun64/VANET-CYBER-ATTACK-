//sabit ivme saldırısı

#pragma once

#include <vasp/attack/Interface.h>

namespace vasp {
namespace attack {
namespace acceleration {
class Constant final : public Interface {
public:
    void attack(veins::BasicSafetyMessage* bsm) override;
};
} // namespace acceleration
} // namespace attack
} // namespace vasp